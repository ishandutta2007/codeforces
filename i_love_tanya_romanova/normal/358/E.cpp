/*
I ride alone, the wasteland that I cross
Will take another life, we'll take another loss
I feel a dry wind, dust is in my eyes
The artic cold at night, the earth, it tells me lies

God in heaven, my only friend
Will I live to see my journey's end?
As the world awakens me so hard, my values have been changed
I make a promise to myself: Never again
A dusty godforsaken path, endless to my dismay
I know these are the badlands, somehow I'll find my way

No more paradise, no more soothing rain
All the sacrifice, the pain is all the same
Still I'm pushing onward, alone I can't deny
My presence fills the desert, my spirit never dies

Will these lonely nights ever end?
Will I live to see my journey's end?
As the world awakens me so hard, my values have been changed
I make a promise to myself: Never again
A dusty godforsaken path, endless to my dismay
I know these are the badlands, somehow I'll find my way

The vultures that circle, cloud the empty sky,
Patiently waiting, they wait for me to die
Tortured and beaten, blistered by the sun
Forceful and heartless, have the badlands won?

Still I'm pushing onward, alone I can't deny
My presence fills the desert, my spirit never dies
As the world awakens me so hard, my values have been changed
I make a promise to myself: Never again
A dusty godforsaken path, endless to my dismay
I know these are the badlands, somehow I'll find my way
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
#define eps 1e-8
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

long n,m,ar[1100][1100];
vector<long> ans;
long arp[1100][1100];
long onv[1100][1100],ong[1100][1100],deg[1100][1100],bad[1100][1100];
long last;
long answ;

long gcd(long a,long b)
{
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
}

void dfs(long a,long b)
{
 arp[a][b]=1;
 if (ar[a][b]==0)return;
 if (arp[a-1][b]==0)dfs(a-1,b);
 if (arp[a+1][b]==0)dfs(a+1,b);
 if (arp[a][b-1]==0)dfs(a,b-1);
 if (arp[a][b+1]==0)dfs(a,b+1);
}

void solve()
{
     long fl=0;
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   if (ar[i][j]==1&&fl==0){dfs(i,j);fl=1;}
 
 /*for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
  cout<<arp[i][j]<<" ";
  cout<<endl;
 }*/
 
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   if (ar[i][j]>arp[i][j])
   {
    ans.push_back(-1);return;
   }
  
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   {
       if (ar[i][j]==0)continue;
       if (ar[i-1][j]+ar[i+1][j])onv[i][j]=1;
       if (ar[i][j-1]+ar[i][j+1])ong[i][j]=1;
       deg[i][j]+=ar[i-1][j];
       deg[i][j]+=ar[i+1][j];
       deg[i][j]+=ar[i][j-1];
       deg[i][j]+=ar[i][j+1];
   } 
  
  long calc=0;
  
  long temp=0;
  
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    if (ar[i][j])++temp;
    
    if (temp==1){ans.push_back(-1);return;}
    
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    if (deg[i][j]%2)++calc;
  
  if (calc!=0&&calc!=2)
  {
   ans.push_back(-1);return;
  }  
  
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   {
    if (deg[i][j]%2>0)bad[i][j]=1;
    if (onv[i][j]&&ong[i][j])bad[i][j]=1;   
   }
   
   long l1;
  
  long answ=0;
  
  /*
  for (int i=1;i<=n;i++)
   {for (int j=1;j<=m;j++)
   cout<<bad[i][j]<<" ";
   cout<<endl;
   }
*/
  for (int i=1;i<=n;i++)
  {
      last=0;
      l1=0;
      for (int j=1;j<=m;j++)
      {
       if (bad[i][j]){if (last!=0)answ=gcd(answ,j-last);last=j;}
      // if (deg[i][j]%2){if (l1!=0)answ=gcd(answ,j-l1);}
       if (ar[i][j])l1=j;
      }
  }
  
  for (int i=1;i<=m;i++)
  {
      last=0;
      l1=0;
      for (int j=1;j<=n;j++)
      {
       if (bad[j][i]){if (last!=0)answ=gcd(answ,j-last);last=j;}
      // if (deg[i][j]%2){if (l1!=0)answ=gcd(answ,j-l1);}
       if (ar[j][i])l1=j;
      }
  }
  
//  cout<<answ<<endl;
if (answ==0)cout<<answ/answ<<endl;

  for (int i=2;i<=1000;i++)
  if (answ%i==0)ans.push_back(i);
  if (ans.size()==0)ans.push_back(-1);
//  return ans;
}
int main(){
//freopen("codes.in","r",stdin);
//freopen("codes.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 cin>>ar[i][j];

solve();
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}