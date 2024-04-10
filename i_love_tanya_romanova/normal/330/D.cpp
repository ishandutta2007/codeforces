/*
Lies, and you'll fill their souls
With all the precious of this world,
And all the glory you'll receive?
So What makes you supreme?
Lies, and your crown is falling.
I offer fantasy, and you,
Create the blind, with envy.

Let the children come to me
Their mother loves me, so shall they
Woman, bleeding, ate my gifts
Man was close behind
Just like a snake I'm slithering
Thru my world divine
And like the cat I'm stalking
I'll take your soul and You'll
Be like me
In emptiness, free

Just bow to me faithfully
Bow to me splendidly
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