/*
All for you
All for you
All for you
All for you

You take your orders from the queen of insanity
But the contract said it was you and me
I sacrificed family, my children and my soul
To give you what you wanted, complete control

All for you
All for you
All for you
All for you

You tried to kill the love and to isolate
But then you turn around, like it's not too late
You justify your actions, forget what you have done
But no more blackmail and no more fun

Day in, day out negativity
Beat me down with your own family
Your bloodline runs in a world of hate
Of dirty white lies and to dominate

Lonely people just trying to find their way
Looking for something but this is the price I pay
Lonely people just trying to find their way
Looking for something but this is the price I pay

All for you
All for you
All for you
All for you

You thought I was stupid, you thought I was blind
You had me by the balls but your well ran dry
You took it all for granted and tried to bring me down
But look at what you've done, take a good look around

Take a good look around
Take a good look around
Come on, take a good look around
Take a look around
What you've got? You've got nothing
Take a look around
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

long cx,cy,n,x[2000];
string dir[2000];

set<long> dx,dy;
set<long>::iterator it;
map<long, long> mx,my,rmx,rmy;
long val;
long calcx,calcy;
long nx,ny;
bool forb[(1<<12)+100][(1<<12)+100];
bool used[(1<<12)+100][(1<<12)+100];
long long ans;

bool cmove(long a,long b)
{
 if (a<=0||b<=0||a>calcx||b>calcy)return false;
 if (used[a][b])return false;
 if (forb[a][b])return false;
 return true;
 
}

void dfs(long a,long b)
{
 used[a][b]=1;
 if (cmove(a-1,b))dfs(a-1,b);
 if (cmove(a+1,b))dfs(a+1,b);
 if (cmove(a,b-1))dfs(a,b-1);
 if (cmove(a,b+1))dfs(a,b+1);
}

void ap(long x,long y)
{
 dx.insert(x);
 dy.insert(y);
 dx.insert(x+1);
 dy.insert(y+1);
}


int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cx=cy=1000000000;

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>dir[i]>>x[i];
 ap(cx,cy);
 if (dir[i]=="U")cx-=x[i];
 if (dir[i]=="D")cx+=x[i];
 if (dir[i]=="L")cy-=x[i];
 if (dir[i]=="R")cy+=x[i];
}

ap(cx,cy);

ap(1,1);


for (it=dx.begin();it!=dx.end();it++)
{
 val=(*it);
 ++calcx;
 mx[val]=calcx;
 rmx[calcx]=val;
}

for (it=dy.begin();it!=dy.end();it++)
{
 val=(*it);
 ++calcy;
 my[val]=calcy;
 rmy[calcy]=val;
}

cx=cy=1000000000;

for (int i=1;i<=n;i++)
{
 nx=cx;
 ny=cy;
 if (dir[i]=="U"){nx-=x[i];for (int j=mx[nx];j<=mx[cx];j++) forb[j][my[cy]]=1;}
 if (dir[i]=="D"){nx+=x[i];for (int j=mx[cx];j<=mx[nx];j++) forb[j][my[cy]]=1;}
 if (dir[i]=="L"){ny-=x[i];for (int j=my[ny];j<=my[cy];j++) forb[mx[cx]][j]=1;}
 if (dir[i]=="R"){ny+=x[i];for (int j=my[cy];j<=my[ny];j++) forb[mx[cx]][j]=1;}
 cx=nx;
 cy=ny;
}

/*for (int i=1;i<=calcx;i++)
 cout<<i<<"  X "<<rmx[i]<<endl;
for (int i=1;i<=calcy;i++)
 cout<<i<<"  Y "<<rmy[i]<<endl;
 */
dfs(1,1);
/*
for (int i=1;i<=calcx;i++)
{
 for (int j=1;j<=calcy;j++)
 {
  cout<<forb[i][j];
 }
 cout<<endl;
}
cout<<"^^"<<endl;
for (int i=1;i<=calcx;i++)
{
 for (int j=1;j<=calcy;j++)
 {
  cout<<used[i][j];
 }
 cout<<endl;
}
cout<<"^^"<<endl;
*/

for (int i=1;i<=calcx;i++)
 for (int j=1;j<=calcy;j++)
 {
  if (used[i][j])continue;
  ans+=(rmx[i+1]-rmx[i])*1ll*(rmy[j+1]-rmy[j]);
 }

cout<<ans<<endl;

cin.get();cin.get();
return 0;}