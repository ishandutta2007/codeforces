/*
You go to the church, you kiss the cross
You will be saved at any cost
You have your own reality
Christianity
You spend your life just kissing ass
A trait that's grown as time has passed
You think the world will end today
You praise the Lord, it's all you say

Jesus saves, listen to you pray
You think you'll see the pearly gates
When death takes you away

For all respect you cannot lust
In an invisible man you place your trust
Indirect dependency
Eternal attempt at amnesty
He will decide who lives and dies
Depopulate Satanas rise
You will be an accessory
Irreverence and blasphemy

Jesus saves, no need to pray
The gates of pearl have turned to gold
It seems you've lost your way

Jesus saves, no words of praise
No promised land to take you to
There is no other way
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,arp[2000][2000],orig[2000][2000],cur[2000][2000],nw[2000][2000];
long ttl;
vector<long> ans;
long answ[200];

void dfs2(long a,long b)
{
     if (arp[a][b])return;
      arp[a][b]=1;
      if (cur[a][b]==1)return;
      if (orig[a][b]==0)return;
      
      dfs2(a-1,b);
      dfs2(a+1,b);
      dfs2(a,b-1);
      dfs2(a,b+1);
      dfs2(a-1,b-1);
      dfs2(a+1,b-1);
      dfs2(a+1,b+1);
      dfs2(a-1,b+1); 
}

long clr[2500][2500];

void dfs1(long a,long b,long cl)
{
 clr[a][b]=cl;
 if (orig[a-1][b]>0&&clr[a-1][b]==0)
 dfs1(a-1,b,cl);
 if (orig[a+1][b]>0&&clr[a+1][b]==0)
 dfs1(a+1,b,cl);
 if (orig[a][b-1]>0&&clr[a][b-1]==0)
 dfs1(a,b-1,cl);
 if (orig[a][b+1]>0&&clr[a][b+1]==0)
 dfs1(a,b+1,cl);
}

long tcl;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/inputt.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>orig[i][j];

for(int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     if (orig[i][j]==1)
     if (clr[i][j]==0){++tcl;dfs1(i,j,tcl);}
 }
 
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cur[i][j]=orig[i][j];

for (int iter=1;iter<=9;iter++)
{
 for (int i=1;i<=n;i++) 
  for (int j=1;j<=m;j++)
   nw[i][j]=(cur[i][j]&cur[i-1][j]&cur[i+1][j]&cur[i][j-1]&cur[i][j+1]);
 
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   cur[i][j]=nw[i][j];
}

for (int iter=1;iter<=14;iter++)
{
 for (int i=1;i<=n;i++) 
  for (int j=1;j<=m;j++)
   nw[i][j]=(cur[i][j]|cur[i-1][j]|cur[i+1][j]|cur[i][j-1]|cur[i][j+1]);
 
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   cur[i][j]=nw[i][j];
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     if (arp[i][j])continue;
     if (orig[i][j]==1&&cur[i][j]==0){
     dfs2(i,j);++answ[clr[i][j]];}
 }
 for (int i=1;i<=tcl;i++)
 ans.push_back(answ[i]);
 
 sort(ans.begin(),ans.end());
 cout<<ans.size()<<endl;
 
 for (int i=0;i<ans.size();i++)
 {
     if (i)cout<<" ";
     cout<<ans[i];
 }
 cout<<endl;
 
cin.get();cin.get();
return 0;}