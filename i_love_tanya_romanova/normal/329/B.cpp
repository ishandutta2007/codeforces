/*
White man came across the sea
He brought us pain and misery
He killed our tribes, he killed our creed
He took our game for his own need

We fought him hard we fought him well
Out on the plains we gave him hell
But many came too much for Cree
Oh will we ever be set free?

Riding through dust clouds and barren wastes
Galloping hard on the plains
Chasing the redskins back to their holes
Fighting them at their own game
Murder for freedom's a stab in the back
Women and children the cowards attack

Run to the hills, run for your lives
Run to the hills, run for your lives

Soldier blue in the barren wastes
Hunting and killing's a game
Raping the women and wasting the men
The only good Indians are tame
Selling them whiskey and taking their gold
Enslaving the young and destroying the old

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.

[Guitar solo]

Yeah oh ah!

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.

Run to the hills,
run for your lives.
Run to the hills,
run for your lives.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m;
long si,sj,ei,ej,ti,tj;
long ans;
pair<long, long> p;
queue<pair<long, long> > qu;
long d[1100][1100];
char ar[1100][1100];
long arp[1100][1100];

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>ar[i][j];
    if (ar[i][j]=='E'){ei=i;ej=j;}
    if (ar[i][j]=='S'){si=i;sj=j;}
}

for(int i=0;i<=n+1;i++)
for (int j=0;j<=m+1;j++)
arp[i][j]=1;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
arp[i][j]=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (ar[i][j]=='T')arp[i][j]=1;

arp[ei][ej]=1;

qu.push(make_pair(ei,ej));

while (qu.size())
{
 p=qu.front();
 qu.pop();
 ti=p.first;tj=p.second;
 if (arp[ti-1][tj]==0)
 {
  arp[ti-1][tj]=1;
  d[ti-1][tj]=d[ti][tj]+1;
  qu.push(make_pair(ti-1,tj));
 }      
 
 if (arp[ti+1][tj]==0)
 {
  arp[ti+1][tj]=1;
  d[ti+1][tj]=d[ti][tj]+1;
  qu.push(make_pair(ti+1,tj));
 }      
 
 if (arp[ti][tj-1]==0)
 {
  arp[ti][tj-1]=1;
  d[ti][tj-1]=d[ti][tj]+1;
  qu.push(make_pair(ti,tj-1));
 }      
 
 if (arp[ti][tj+1]==0)
 {
  arp[ti][tj+1]=1;
  d[ti][tj+1]=d[ti][tj]+1;
  qu.push(make_pair(ti,tj+1));
 }      
 
}
ans=0;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (arp[i][j]==1&&d[i][j]<=d[si][sj]&&ar[i][j]>='0'&&ar[i][j]<='9')
ans+=ar[i][j]-48;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}