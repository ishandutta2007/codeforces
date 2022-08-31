/*
We lie awake and try to reason why
These people treat us so unkind
Just wanna taste the freedom one more time
Just wanna leave it all behind, yeah

We sneak down the hallway, it's time for us to go
It's time for them to let us be, yeah
So close to heaven, I can almost see the light
A few more steps and we'll be free, yeah
Oh, leave it all behind

We gotta go right now
We gotta go, they are coming for us
We have to leave right now
Shh, I think I hear their footsteps
We gotta run like hell

Breaking out in silence as we crawl beneath the gate
Run, run so much fun, doesn't it feel great?
Over the wall, the great escape, we pledge you this and vow
That you'll never ever catch us, you'll never get us now

Breathing hard, we got to get away
Never going back to yesterday
Run and hide from the enemy
But you can't stop the both of me

Racing through the darkness as we slice into the night
There's no one here to challenge us, our freedom's now in sight
But something moves around us, they've seen through our disguise
Flashing lights surround us, they begin to multiply

Breathing hard, we got to get away
Never going back to yesterday
Run and hide from the enemy
But you can't stop the both of me

Breathing hard, we got to get away
Never going back to yesterday
Run and hide from the enemy
But you can't stop the both of me

Sirens, well, they're right behind us, but I know what to do
It's time for us to say, goodbye, time to split in two
Returning there is not an option, we've never going back
You cage us like an animal, prepare for the attack

Breathing hard, we got to get away
Never going back to yesterday
Run and hide from the enemy
But you can't stop the both of me

Breathing hard, we got to get away
Never going back to yesterday
Run and hide from the enemy
But you can't stop the both of me
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