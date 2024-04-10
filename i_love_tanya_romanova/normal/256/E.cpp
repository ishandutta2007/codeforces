/*
Infernal ritual from a black plague
Desecreates my existence for it's curse
Out of flesh and unconscious like a worm
The eyes of horror behold my sacrifice
Raised up from a serpent's stream
At the realm of ancient gods I am reborn
Bearer of mighty wrath-darknest power is conceived
Sworn to deey all in sight death
And rebellion I proclaim

Surrounded by pure damnation
Everything's suffer before me
Shinning effigy of desolation
Suffocates the key of salvation
Violent incantation evokes
Infamous order prevails
Possessed by repulsing command
Let the fatal century begin
Pouring blood from saint's slaughter
As the frosty skies get covered in black

Swallowed in abhorrent dimension
All signs of the holiness turns reversed
Molested promises of pagan decay
Enthroning legions of immortality
Tyrant hatred supreme
I swear I see the scourge of creation

Infernal ritual from a black plague
Desecreates my existence for it's curse
Out of flesh and unconscious like a worm
The eyes of horror behold my sacrifice
Raised up from a serpent's stream
At the realm of ancient gods I am reborn
Bearer of mighty wrath-darknest power is conceived
Sworn to deey all in sight death
And rebellion I proclaim
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
#define bs 777777777
#define bsize 256

using namespace std;

long ar[200000];
long n,m;
long nice[20][20];
long a,b;

long vl[300000][4][4];

long gett()
{
 long ans=0;
 for (int l=1;l<=3;l++)
  for (int r=1;r<=3;r++)
   ans+=vl[1][l][r],
   ans%=bs;
 return ans;
}

void build1(long v,long l,long r)
{
 if (l==r)
 {
  for (int j=1;j<=3;j++)
  {
   vl[v][j][j]=1;
  }
  return;
 }
 long mid=l+r;
 mid/=2;
 build1(v*2,l,mid);
 build1(v*2+1,mid+1,r);
 
 for (int a=1;a<=3;a++)
  for (int b=1;b<=3;b++)
   for (int cut1=1;cut1<=3;cut1++)
    for (int cut2=1;cut2<=3;cut2++)
    if (nice[cut1][cut2])
    {
     long long temp=vl[v*2][a][cut1]*1ll*vl[v*2+1][cut2][b];
     temp%=bs;
     vl[v][a][b]=vl[v][a][b]+temp;
     vl[v][a][b]%=bs;
    }
}


void build(long v,long l,long r,long ps,long val)
{
 if (l==r)
 {
  ar[ps]=val;
  for (int i=1;i<=3;i++)
   for (int j=1;j<=3;j++)
   {
    vl[v][i][j]=0;
   }
   
  for (int j=1;j<=3;j++)
  {
   if (ar[ps]==0||ar[ps]==j)
    vl[v][j][j]=1;
  }
  
  return;
 }
 long mid=l+r;
 mid/=2;
 if (ps<=mid)build(v*2,l,mid,ps,val);
 else build(v*2+1,mid+1,r,ps,val);
 
 for (int j=1;j<=3;j++)
  for (int q=1;q<=3;q++)
   vl[v][j][q]=0;
 
 for (int a=1;a<=3;a++)
  for (int b=1;b<=3;b++)
   for (int cut1=1;cut1<=3;cut1++)
    for (int cut2=1;cut2<=3;cut2++)
    if (nice[cut1][cut2])
    {
     long long temp=vl[v*2][a][cut1]*1ll*vl[v*2+1][cut2][b];
     temp%=bs;
     vl[v][a][b]=vl[v][a][b]+temp;
     vl[v][a][b]%=bs;
    }
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=3;i++) 
 for (int j=1;j<=3;j++)
  cin>>nice[i][j];

build1(1,1,n);

build(1,1,n,1,0);

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 build(1,1,n,a,b);
 cout<<gett()<<endl;
}

cin.get();cin.get();
return 0;}