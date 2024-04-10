/*
All that I need is the air that I breathe
And all that I need are things I don't need
And all that really matters is what matters to me
And who of you are like me?

If I was to smile and I held out my hand out
And opened it now would you not understand?
Because you know if I'm to benefit I'll do everything that I can
And who of you are like me?

It will make you feel good, over my shoulder
It'll get me down and got me tied up
'Till I grow older but feel me inside of you
Like you want it to

But is it just the pains in your head
That are thrilling me
Another life's falling down onto it's knees
But I'll never smile the way, that I did like that day
Everything will be okay, everything will be okay
It'll be okay
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

using namespace std;

long n,m;
string st;
long bad[1600][1600];
pair<long, long> was[1600][1600];

long gett(long x,long mod)
{
 x%=mod;
 if (x<0)x+=mod;
 return x;
}

pair<long, long> zr;
long ans;
pair<long, long> start;
bool cmove(long x,long y)
{
long tx,ty;
tx=gett(x,n);
ty=gett(y,m);
if (bad[tx][ty])return false;
return true;
}

void dfs(long x,long y)
{
 long tx,ty;
 tx=gett(x,n);
 ty=gett(y,m);
 if (was[tx][ty]!=zr&&was[tx][ty]!=make_pair(x,y))ans=1;
 if (ans)return;
 if (was[tx][ty]==make_pair(x,y))return;
 was[tx][ty]=make_pair(x,y);
 if (cmove(x-1,y))dfs(x-1,y);
 if (cmove(x+1,y))dfs(x+1,y);
 if (cmove(x,y-1))dfs(x,y-1);
 if (cmove(x,y+1))dfs(x,y+1);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
 for (int j=0;j<m;j++) 
 was[i][j]=make_pair(-1000000,-1000000);
zr=make_pair(-1000000,-1000000);

for (int i=0;i<n;i++)
{
 cin>>st;
 for (int j=0;j<m;j++)
 {
  if (st[j]=='#')bad[i][j]=1;
  if (st[j]=='S')start=make_pair(i,j);
 }
}

dfs(start.first,start.second);

if (ans)cout<<"Yes"<<endl;
else cout<<"No"<<endl;

cin.get();cin.get();
return 0;}