/*
A broken window
An open door,
A cold wind blowming,
Some leaves strewn about the floor,,
Rain drops falling down the ceiling
A wall with cracking paint
Something dead in the sink
Is this wold lost?
Where's common sens?
Nothing more to say
I cannot believe my eyes!
Is this world a ghost,
A dead man waiting,
A forgotten king?
I can not believe my eyes! (I don't know!)
I'm out of breath
Is that the better life that you promised?
I'm out of breath
I don't want to realize it is hopeless
Are better days to come?
Is that life changing?
Will I find my breath again?
I feel drained
I feel drained
From fighting fears each day
I feel drained
I Feel drained
Who could accept to live this way?
I'm so tired of feeling ashamed
Of living this way
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

long n,ar[2000];
pair<long, long> crd[2000];
long dwn,up;
long d,ti,tj;
long mx[2000];
char ans[1200][1200];

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
long s=0;
cin>>n;
for (int i=1;i<=n;i++){
 cin>>ar[i];s+=ar[i];}

crd[0]=make_pair(0,0);
for (int i=1;i<=n;i++)
{
 crd[i]=crd[i-1];
 crd[i].second+=ar[i];
 if (i%2==1)crd[i].first+=ar[i];
 else crd[i].first-=ar[i];
}
/*
for (int i=0;i<=n;i++)
 cout<<crd[i].first<<" "<<crd[i].second<<endl;
 cout<<endl;
 */
for (int i=0;i<=n;i++)
 dwn=min(dwn,crd[i].first);
for (int i=0;i<=n;i++)
 crd[i].first-=dwn;
/*
for (int i=1;i<=n;i++)
cout<<crd[i].first<<" "<<crd[i].second<<endl;
cout<<endl;
*/
for (int i=1;i<=n;i++)
 up=max(up,crd[i].first);
 
for (int i=0;i<n;i++)
{
 d=abs(crd[i+1].first-crd[i].first);
 if (i%2==0)
  for (int ii=0;ii<d;ii++)
   {
    ti=crd[i].first+ii;
    tj=crd[i].second+ii;
    mx[ti]=max(mx[ti],tj);
    ans[ti][tj]='/';
   }
  else
  
  for (int ii=0;ii<d;ii++)
   {
    ti=crd[i].first-ii-1;
    tj=crd[i].second+ii;
    mx[ti]=max(mx[ti],tj);
    ans[ti][tj]='\\';
   }
}

for (int i=up-1;i+1;--i)
{
 for (int j=0;j<s;j++)
 if (ans[i][j]>0)cout<<ans[i][j];else cout<<" ";
 cout<<endl;
}
cin.get();cin.get();
return 0;}