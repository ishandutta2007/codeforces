/*
Girl you'll go far

Engines on
We're heading out of here
Hell's lost son
Will take you in his care

Reload
Don't close your eyes
We'll shoot our way out

Reload
Don't close your eyes
Go dynamite

The cops are looking for you
And they will come for me too, don't hide
I need you now, so stay cool

We have to go, we'll break through, we ride
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,tp[20000],a[20000],b[20000],c[20000],fl,bad;
long upl[10000];
long sett[10000];
long ans[10000];

int main(){
//freopen("supper.in","r",stdin);
//freopen("supper.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>tp[i]>>a[i]>>b[i]>>c[i];
}

for (int i=1;i<=n;i++)
upl[i]=500000000;

for (int i=1;i<=n;i++)
sett[i]=0;

for (int i=m;i;--i)
{
    /*
    for (int j=1;j<=n;j++)
    cout<<upl[j]<<" ";cout<<endl;
    for (int j=1;j<=n;j++)
    cout<<sett[j]<<" ";
    cout<<endl;
    */
    if (tp[i]==1)for (int j=a[i];j<=b[i];j++)
     upl[j]-=c[i];
    else
    {
     fl=0;
     for (int j=a[i];j<=b[i];j++)
     {
      upl[j]=min(upl[j],c[i]);
  //    sett[j]=1;
     }
//     if (fl==0)bad=1;
    }
}
/*
for (int i=1;i<=n;i++)
cout<<upl[i]<<" ";
cout<<endl;
*/
for (int i=1;i<=n;i++)
ans[i]=upl[i];

for (int i=1;i<=m;i++)
{
    
    if (tp[i]==1)for (int j=a[i];j<=b[i];j++)
     upl[j]+=c[i];
    else
    {
     fl=0;
     for (int j=a[i];j<=b[i];j++)
     {
      if (upl[j]==c[i])fl=1;
     }
     if (fl==0)bad=1;
    }
}

if (bad)cout<<"NO"<<endl;
else 
{
     cout<<"YES"<<endl;
     for (int i=1;i<=n;i++)
     {
         if(i-1)cout<<" ";
         cout<<ans[i];
     }
     cout<<endl;
 }

cin.get();cin.get();
return 0;}