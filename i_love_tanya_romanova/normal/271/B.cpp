/*
Wake up (wake up)
Grab a brush and put a little make-up
Hide the scars to fade away the shake-up
Why'd you leave the keys upon the table?
Here you go create another fable

You wanted to
Grab a brush and put a little makeup
You wanted to
Hide the scars to fade away the shake-up
You wanted to
Why'd you leave the keys upon the table?
You wanted to

I don't think you trust
In my self-righteous suicide
I cry when angels deserve to die, die

Wake up (wake up)
Grab a brush and put a little make-up
Hide the scars to fade away the shake-up
Hide the scars to fade away the
Why'd you leave the keys upon the table?
Here you go create another fable

You wanted to
Grab a brush and put a little make-up
You wanted to
Hide the scars to fade away the shake-up
You wanted to
Why'd you leave the keys upon the table?
You wanted to

I don't think you trust
In my self-righteous suicide
I cry when angels deserve to die
In my self-righteous suicide
I cry when angels deserve to die

Father, father, father, father
Father, into your hands I commend my spirit
Father, into your hands
Why have you forsaken me?
In your eyes forsaken me
In your thoughts forsaken me
In your heart forsaken me, oh

Trust in my self-righteous suicide
I cry when angels deserve to die
In my self-righteous suicide
I cry when angels deserve to die
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long ans,tans,pr[500000],n,m,ad[500000],ar[1000][1000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;
for (int i=2;i<=200000;i++)
{
    if (pr[i]==0)for (int j=i*2;j<=200000;j+=i)
    pr[j]=1;
}

for (int i=200000;i;--i)
if (pr[i]==0)ad[i]=0;else ad[i]=ad[i+1]+1;


cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>ar[i][j];

ans=1000000000;
for (int i=1;i<=n;i++)
{
    tans=0;
    for (int j=1;j<=m;j++)
    tans+=ad[ar[i][j]];
    ans=min(ans,tans);
}

for (int i=1;i<=m;i++)
{
    tans=0;
    for (int j=1;j<=n;j++)
    tans+=ad[ar[j][i]];
    ans=min(ans,tans);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}