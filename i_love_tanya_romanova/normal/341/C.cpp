/*
My eyes seek reality
My fingers seek my veins
Theres a dog at your back step
He must come in from the rain

I fall cause I let go
The net below has rot away
So my eyes seek reality
And my fingers seek my veins

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me

My eyes seek reality
My fingers feel for faith
Touch clean with a dirty hand
I touched the clean to the waste

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

And I cry, to the alley way
Confess all to the rain
But I lie, lie straight to the mirror
The one I've broken, to match my face

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you (yeah)
Of what is done and to do (yeah)
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

My eyes seek reality
My fingers seek my veins
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
#include <memory.h>

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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long n,ar[3000],c[2100][2100],hput,cpos;
long long ar1[3000],ar2[3000];
long long fact[5000],ways[5000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=0;i<=2000;i++)
for (int j=0;j<=2000;j++)
if (j==0||j==i)c[i][j]=1;
else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

for (int i=1;i<=n;i++)
if (ar[i]==-1)ar1[i]=1;

for (int i=1;i<=n;i++)
if (ar[i]>0)ar2[ar[i]]=1;

for (int i=1;i<=n;i++)
if (ar1[i]==1&&ar2[i]==0)
hput++;

//i-e mod Q
// gpq

for (int i=1;i<=n;i++)
if (ar1[i]==1)
cpos++;

//cout<<cpos<<" "<<hput<<endl;

fact[0]=1;
for (int i=1;i<=2500;i++)
fact[i]=fact[i-1]*i%bs;

for (int bad=0;bad<=hput;bad++)
ways[bad]=c[hput][bad]*fact[cpos-bad]%bs;
/*
for (int i=0;i<=hput;i++)
cout<<ways[i]<<" ";
cout<<endl;
*/

// lput, %bs

for (int i=hput-1;i>=0;i--)
for (int j=i+1;j<=hput;j++)
{
    ways[i]=ways[i]-ways[j]*c[j][i]%bs;
    while (ways[i]<0)ways[i]+=bs;
}

/*
for (int i=0;i<=hput;i++)
cout<<ways[i]<<" ";
cout<<endl;
*/

//http://oeis.org/A000166
cout<<ways[0]<<endl;

cin.get();cin.get();
return 0;}