/*
Mouthful of cavities
Your soul's a bowl of jokes
And everyday you remind me
How I'm desperately in need

See, I got a lot of fiends around
And they're peaking through nothing new
They see you
They see everything you do
See everything on the inside, out

Oh, please give me a little more
And I'll push away those baby blues
'Cause one of these days this will die
So will me and so will you

I write a letter to a friend of mine
I tell him how much I used to love watch him smile
See I haven't seen him smile in a little while
Haven't seen him smile in a little while

But I know you're laughing from the inside out
Laughin' from the inside out
I know you're laughing from the inside out
Laughing from the inside
From the inside, from the inside out
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