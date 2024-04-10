/*
Though it's nothing new: we still rob our planet
It's the daily truth, we interfere with everything
Annihilation of our life's space - it is such a

Wasteland
Nothing can exist without being disturbed
Civilization kills!
Wasteland
Sooner or later we'll transform a system
That's already been perfect

It's always been the same, we take
Ourselves too serious
We're not the best of all, we are just a part of it
Is there any race as destructive as we are?

Wasteland
Children are dying for what they do not see
Ideology kills!
Wasteland
Knowledge is something for people with reason,
With responsibility

Wasteland
The more we even learn
Wasteland
The less we understand
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

long n,m,l[500000],r[500000],col[500000],ar1[500000],ar2[500000];

void sett(long l, long r,long col)
{
     //upd p
     if (ar2[l/bsize]!=-1)
     {
      for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
      {
       ar1[i]=ar2[i/bsize];
      }
      ar2[l/bsize]=-1;
     }
     
     while (l<=r&&l%bsize>0)
     {
      ar1[l]=col;++l;
     }
     
     while (l+bsize<=r)
     {
      ar2[l/bsize]=col;l+=bsize;
     }
     
     //upd q
     if (ar2[l/bsize]!=-1)
     {
      for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
      {
       ar1[i]=ar2[i/bsize];
      }
      ar2[l/bsize]=-1;
     }
     
     while (l<=r)
     {
      ar1[l]=col;++l;
     }
}

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=0;i<=n;i++)
ar2[i]=-1;

for (int i=1;i<=m;i++)
{
    cin>>l[i]>>r[i]>>col[i];
}
for (int i=m;i;--i)
{
    sett(l[i],col[i]-1,col[i]);
    sett(col[i]+1,r[i],col[i]);
}

for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 if (ar2[i/bsize]!=-1)cout<<ar2[i/bsize];else cout<<ar1[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}