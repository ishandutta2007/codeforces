/*
You ever hear the story of Mr. Faded Glory?
Say he who rides a pony must someday fall
I've been talkin' to my alter, says "Life is what you make it
And if you make it death well rest your soul away, away, away"

It's a broken kind of feeling, she'd have to tie me to the ceiling
A bad moon's comin', better say your prayers
I wanna tell her that I love her, but does it really matter?
I just can't stand to see you dragging down again, again, again

So I'm singing, oh this is my kinda love
It's the kind that moves on
It's some kind that leaves me alone, you know
Oh this is my kinda love
It's the kind that moves on
It's the kind that leaves me alone

I used to treat you like a lady, now you're my substitute teacher
This bottle's not a pretty, not a pretty sight
I owe the man some money, so I'm turnin over honey
Yes, Mr. Faded Glory is once again doin' time, yeah

This is my kinda love
It's the kind that moves on
It's the kind that leaves me alone
Now this is my kinda love
It's the kind that moves on
It's the kind that, it's the kind that

Leaves me alone
Like a crown of thorns
It's all who you know
So don't burn your bridges, woman
'Cause someday, yeah

So I'm singing
This is my kinda love
It's the kind that moves on
It's the kind that leaves you alone, yeah
This is my kinda love
It's the kind that moves on
It's the kind that, kind that leaves me alone

Like a crown of thorns
It's all who you know
Come on, come on, come on
Don't burn your bridges, woman
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,m;
string st;
long bad[1<<10][1<<10];
long cv,cg;
vector<pair<long,long> > ans;
long bi,bj;
long qi,qj,brushed[1<<11][1<<11];
long s[1<<11][1<<11];
long li,lj;
long u[1<<11][1<<11],l[1<<11][1<<11];
long bst;
long iter;
long ttl;

long gs(long x1,long y1,long x2,long y2)
{
 return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void check(long brushi,long brushj)
{
 qi=bi;
 qj=bj;
 
 if (bad[qi+brushi][qj]==1&&bad[qi][qj+brushj]==1){return;}
 if (gs(qi,qj,qi+brushi-1,qj+brushj-1)!=(brushi*brushj))return;
 
 int done=brushi*brushj;
 int ts=done;

 long er=0;
 while (true)
 {
  if (bad[qi+brushi][qj]==0&&bad[qi][qj+brushj]==0)break;
  if (bad[qi+brushi][qj]==1&&bad[qi][qj+brushj]==1){er=1;break;}
  if (bad[qi+brushi][qj])
  {
   done+=gs(qi+brushi,qj,qi+brushi,qj+brushj-1);
   ts+=brushj;
   ++qi;
  }
  else
  {
   done+=gs(qi,qj+brushj,qi+brushi-1,qj+brushj);
   ts+=brushi;
   ++qj;
  }
 }
 if(er)return;
 
// cout<<done<<"%"<<" "<<brushi<<" "<<brushj<<endl;
 if (done!=ttl||ts!=ttl)return;
   
     ans.push_back(make_pair(brushi,brushj));

}

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
  if (st[j-1]=='X')
   bad[i][j]=1;
   else bad[i][j]=0;
 for (int j=1;j<=m;j++)
  if (bad[i][j])++ttl;
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     if (bad[i][j]>0&&bi==0)
      bi=i,bj=j;
     if (bad[i][j]>0)
     {if (li<i)li=i;if (lj<j)lj=j;}
 }

for (int i=1;i<=n;i++) 
 for (int j=1;j<=m;j++)
 {
  s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+bad[i][j];
 }

if (gs(bi,bj,li,lj)==(li-bi+1)*(lj-bj+1))// rect
{
 cout<<min(li-bi+1,lj-bj+1)<<endl;
 return 0;
}

cv=cg=1000;

for (int i=1;i<=n+1;i++)
 for (int j=1;j<=m+1;j++)
 {
  u[i][j]=u[i-1][j]+1;
  l[i][j]=l[i][j-1]+1;
  if (u[i-1][j]>0&&bad[i][j]==0)
   cv=min(cv,u[i-1][j]);
  if (l[i][j-1]>0&&bad[i][j]==0)
   cg=min(cg,l[i][j-1]);
  if (bad[i][j]==0)
   u[i][j]=l[i][j]=0;
 }
 //cout<<cv<<" "<<cg<<endl;



cv=cg=0;
for (int i=bi;i<=n;i++)
 if (bad[i][bj])++cv;
  else break;
for (int i=bj;i<=m;i++)
 if (bad[bi][i])++cg;
 else break;

for (int i=1;i<=cv;i++)
{++iter; check(i,cg);}
for (int i=1;i<=cg;i++)
{++iter;
 check(cv,i);}
 
if (ans.size()==0)cout<<-1<<endl;
else 
{
 bst=1e9;
 for (int i=0;i<ans.size();i++)
  bst=min(bst,ans[i].first*ans[i].second);
 cout<<bst<<endl;
}

cin.get();cin.get();
return 0;}