/*
In a churchyard by a river,
Lazing in the haze of midday,
Laughing in the grasses and the graze.
Yellow bird, you are alone in singing and in flying on,
In and in leaving. Willow weeping in the water,
Waving to the river daughters,
Swaying in the ripples and the reeds.
On a trip to Cirrus Minor, saw a crater in the sun
A thousand miles of moonlight later.
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

long n,m,k,ar[666][666];
string st;
long arp[666][666];
long bad[666][666];

void dfs(long a,long b)
{
 arp[a][b]=1;
 if (arp[a-1][b]==0&&ar[a-1][b]==0)dfs(a-1,b);
 if (arp[a+1][b]==0&&ar[a+1][b]==0)dfs(a+1,b);
 if (arp[a][b-1]==0&&ar[a][b-1]==0)dfs(a,b-1);
 if (arp[a][b+1]==0&&ar[a][b+1]==0)dfs(a,b+1);
 if (k>0){bad[a][b]=1;--k;}
}
int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
  
  
  cin>>n>>m>>k;
  
  for (int i=0;i<=n+2;i++)
   for (int j=0;j<=m+2;j++)
    ar[i][j]=1;
    
  for (int i=1;i<=n;i++)
   {
    cin>>st;
    for (int j=1;j<=m;j++)
     if (st[j-1]=='.')ar[i][j]=0;
   }
   
   for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
     if (ar[i][j]==0&&arp[i][j]==0)
     {
      dfs(i,j);
     }
    }
 
 for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
  {
  if (bad[i][j])cout<<"X";else if (ar[i][j]==0)cout<<".";else cout<<"#";
  }
  cout<<endl;
 }

cin.get();cin.get();
return 0;}