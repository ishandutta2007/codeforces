/*
Pain makes me
Stronger everyday
Life is chaos
You gotta deal with it

Expressing my aggressions
Through confusion
Face reality
Nothing's like it used to be

Don't tell me I don't know
You don't live in my war
Revolt and anger
I won't take it anymore

Don't get me wrong
(You don't know where I'm from)
Don't get me wrong
(You don't know where I've been)

Don't get me wrong
(Been a painful way)
Don't get me wrong
(You wouldn't understand)

Soul, mind, fist
Soul, mind, fist

Soul, mind, fist
Soul, mind, fist
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m;
string st;
char ar[1100][1100];
long ans;
long arp[1100][1100];
long fl;
char need[10];
long aw[1200][1200];

void dfs(long a,long b,long dep)
{
 if (fl)return;
 arp[a][b]=1;
 
 if (ar[a-1][b]==need[dep%4])
 {
  if (arp[a-1][b]==1){fl=1;return;}
  if (arp[a-1][b]==0)dfs(a-1,b,dep+1);
  aw[a][b]=max(aw[a][b],aw[a-1][b]);
 }
 
 
 if (ar[a+1][b]==need[dep%4])
 {
  if (arp[a+1][b]==1){fl=1;return;}
  if (arp[a+1][b]==0)dfs(a+1,b,dep+1);
  aw[a][b]=max(aw[a][b],aw[a+1][b]);
 }
 
 if (ar[a][b-1]==need[dep%4])
 {
  if (arp[a][b-1]==1){fl=1;return;}
  if (arp[a][b-1]==0)dfs(a,b-1,dep+1);
  aw[a][b]=max(aw[a][b],aw[a][b-1]);
 }
 
 
 if (ar[a][b+1]==need[dep%4])
 {
  if (arp[a][b+1]==1){fl=1;return;}
  if (arp[a][b+1]==0)dfs(a,b+1,dep+1);
  aw[a][b]=max(aw[a][b],aw[a][b+1]);
 }
 
 aw[a][b]++;
 arp[a][b]=2;
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

need[1]='I';need[0]='D';need[2]='M';need[3]='A';

for(int i=1;i<=n;i++)
 {
  cin>>st;
  for (int j=1;j<=m;j++)
  {
   ar[i][j]=st[j-1];
  }
 }


for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (ar[i][j]=='D'&&arp[i][j]==0)
   dfs(i,j,1);
 
 for (int i=1;i<=n;i++){
  for (int j=1;j<=m;j++){
//  cout<<aw[i][j]<<" ";
  ans=max(ans,aw[i][j]);}//cout<<endl;
  }
  
  
 if (fl)cout<<"Poor Inna!"<<endl;
 else if (ans<4)cout<<"Poor Dima!"<<endl;
 else cout<<ans/4<<endl;
 
cin.get();cin.get();
return 0;}