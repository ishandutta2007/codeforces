/*
You're gone, you're gone

Your body's cold, hope is lost, I can't let go
Can I die with you so we can never grow old?
Cut the ties, cut the ties with this note you left behind
As I read the words I hear you telling me why

Too late, too late, I never said goodbye
Too late, too late, can't even ask you why
And now I'm wasting away in my own misery
I hope you're finally gone to a place where you belong

My sadness shows as your name is carved in stone
Can't erase the words so the reality grows
I wish I'd died on that night right by your side
So just kill me now and let the good times roll

Too late, too late, I never said goodbye
Too late, too late, can't even ask you why
And now I'm wasting away in my own misery
I hope you're finally gone to a place where you belong

Will you wait for me? Will you wait for me?
Will I see you on the other side?
You don't have to wait too long, yeah, yeah
Will you come to me? Will you come to me?
Will you take me to the other side
'Cause here I don't belong

Too late, too late, I never said goodbye
Too late, too late, can't even ask you why
And now I'm wasting away in my own misery
I hope you're finally gone to a place where you belong

I never said goodbye, oh, can't even ask you why
I'm wasting away in my own misery
I hope you're finally gone to a place where you belong
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long  n,m,k;
long ar[1<<17][7];

long  t[1<<19][7];
long l,r,mid;
long found;

void build(long v,long l,long r)
{
 if (l==r)
 {
  for( int j=0;j<m;j++)
   t[v][j]=ar[l][j];
   return;
 }
 long tm=l+r;
 tm/=2;
 build(v*2,l,tm);
 build(v*2+1,tm+1,r);
 for (int j=0;j<m;j++)
  t[v][j]=max(t[v*2][j],t[v*2+1][j]);
}

long get(long v,long tl,long tr,long l,long r,long id)
{
 if (l>r) return 0;
 if (tl==l&&tr==r)
  return t[v][id];
 long tm=tl+tr;
 tm/=2;
 long a=get(v*2,tl,tm,l,min(r,tm),id);
 if (a>k)return a;
 return max(a,get(v*2+1,tm+1,tr,max(l,tm+1),r,id));
}

vector<long> vec;

multiset<long> S[10];
multiset<long>::iterator it;

long safe_add(long a,long b)
{
 if (2e9-b<=a)
  return 2e9;
  return a+b;
}

long solve(long l,long r)
{
 long s=0;
 vec.clear();
 for (int i=0;i<m;i++)
 {
  long ts=get(1,0,n-1,l,r,i);
  vec.push_back(ts);
  s=safe_add(s,ts);
 }
 return s;
}

long mx[1<<17][6][21];

long eval(long a,long b)
{
 if (a>b)
 {
  for (int i=0;i<m;i++)
   vec[i]=0;
   return 0;
 }
 long s=0;
 long t=1;
 long itr=0;
 while (t*2<=b-a+1)
  t*=2,itr++;
  
///  cout<<a<<"  "<<b<<" "<<t<<endl;
 for (int i=0;i<m;i++)
 {
     s+=max(mx[a][i][itr],mx[b-t+1][i][itr]);
   //  cout<<mx[a][i][itr]<<"   "<<mx[b-t+1][i][itr]<<" "<<b-t+1<<" "<<itr<<endl;
     vec[i]=max(mx[a][i][itr],mx[b-t+1][i][itr]);
 }
 return s;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=0;i<n;i++)
{
 for (int j=0;j<m;j++)
  cin>>ar[i][j];
}

for (int i=0;i<n;i++)
 for (int j=0;j<m;j++)
 {
     mx[i][j][0]=ar[i][j];
}


     for (int lev=1;lev<=18;lev++)
     for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
     {mx[i][j][lev]=mx[i][j][lev-1];if (i+(1<<lev)/2<n)mx[i][j][lev]=max(mx[i][j][lev],mx[i+(1<<lev)/2][j][lev-1]);
     //if (lev==2)cout<<i<<"  "<<j<<" "<<mx[i][j][0]<<" "<<mx[i][j][1]<<"  "<<mx[i][j][2]<<endl;
     }

//build(1,0,n-1);

vec.resize(m);
l=0;
r=n;
while (l<r)
{
/* if (k==499992178)
  cout<<l<<" "<<r<<" "<<mid<<endl;*/
 mid=l+r+1;
 mid/=2;
 found=-1;
 for (int i=0;i<5;i++)
  S[i].clear();
 
 for (int i=0;i+mid-1<n;i++)
 {
     if (eval(i,i+mid-1)<=k)
      found=i;
     if (found!=-1)
      break;
 }
 if (found==-1)
  r=mid-1;
  else l=mid;
}

mid=l;
 found=-1;
 
 for (int i=0;i+mid-1<n&&found==-1;i++)
 {
     if (eval(i,i+mid-1)<=k)
      {found=i;break;}
 }
 
for (int i=0;i<vec.size();i++)
{
 if (i)cout<<" ";
 cout<<vec[i];
}
cout<<endl;

//cout<<l<<endl;

cin.get();cin.get();
return 0;}