/*
Waiting the hour destined to die
Here on the table of hell
A figure in white unknown by man
Approaching the altar of death
High priest awaiting dagger in hand
Spilling the pure virgin blood
Satan's slaughter, ceremonial death
Answer his every command

Death will come easy just close your eyes -
Dream of the friends you'll see
Heavenly failure losing again
Move on to a new form of life

Altar of sacrifice, curse of the damned
Confronting the evil you dread
Coalesce into one your shadow and soul
Soon you will meet the undead

(Altar of sacrifice, curse of the damned
Confronting the evil you dread
Coalesce into one your shadow and soul
Soon you will meet the undead)

Enter to the realm of Satan!

Blood turning black, the change has begun
Feeling the hatred of all damned in Hell
Flesh starts to burn, twist and deform
Eyes dripping blood realization of death
Transforming of five toes to two
Learn the sacred words of praise, hail Satan

A gift of powers disposed upon you
Use them when you feel the need
Master the forces and powers of Satan
Controlling the creature's instinct
Drawn to the castles that float in the sky
Learn to resist the temptation
Watching the angels sift through the heavens
Endlessly searching for salvation
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