/*
The atmosphere around you is dark and cold
You're only seventeen but in your heart you're feeling old
But one day you will leave this place of fear
Escape to somewhere far away far away from here

A grain of sand at the ocean shore
Faceless lost with the urge for more
Can't break free suffering in pain
Following the Everlasting Flame

The factory walls here leave no room to breath
You're thirty four and some old friends became only memories
And still you need to hide your bitter tears
And dream of somewhere far away far away from here

Swallowed by this material world
Pre ordained from his death to birth
Can't break free suffering
Following the Everlasting Flame

There's just no way out of this living hell
You're fifty six now just a shadow of your broken self
A wasted life the pain won't disappear
You'll never see a better place far away from here

Swallowed by this material world
Pre ordained from his death to birth
Can't break free suffering
Following the Everlasting Flame
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
#define eps 1e-9
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
#define N 4000005
using namespace std;

vector<long> mx,my;
vector<char> mt;
long arp[600][600];
char ar[600][600];
long a,b,n,m,pi,pj;

void add(long a,long b,long tp)
{
 mx.push_back(a);my.push_back(b);
 if (tp==0)
 mt.push_back('D');
 else if (tp==1)
 mt.push_back('B');
 else mt.push_back('R');
}

void dfs(long a,long b)
{
 arp[a][b]=1;
 add(a,b,1);
 if (arp[a-1][b]==0&&ar[a-1][b]=='.')dfs(a-1,b);
 if (arp[a+1][b]==0&&ar[a+1][b]=='.')dfs(a+1,b);
 if (arp[a][b-1]==0&&ar[a][b-1]=='.')dfs(a,b-1);
 if (arp[a][b+1]==0&&ar[a][b+1]=='.')dfs(a,b+1);
 if (a!=pi||b!=pj)
 {
  add(a,b,0);add(a,b,2);
 }
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 cin>>ar[i][j];   
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (ar[i][j]=='.'&&arp[i][j]==0)
{
 pi=i;pj=j;
 dfs(i,j);
}

cout<<mx.size()<<endl;
for (int i=0;i<mx.size();i++)
{
    cout<<mt[i]<<" ";
    cout<<mx[i]<<" "<<my[i]<<endl;
}
cin.get();cin.get();
return 0;}