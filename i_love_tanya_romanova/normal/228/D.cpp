/*
Questions arise from the unknown
Confusion brings curiosity
Whispers come as many regrets they've buried in the past
To witness the unreal... the unreal
A vision unfolds before my eyes
A vision of cold and pale gray skies
Minutes seem like hours
Alone we sit and stare and wait for them to come
To witness the unreal... the unreal
What's false - What's real - Truth is unknown
Serious - Mysterious - Are we alone
Voices from the black call to me
The eyes up in the void watching me
There lies in the skies secrets we seek
They're lies to mystify to keep us week
Echoes of the past reminding me
The lights up in the sky... unreality
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,ar[1<<20];
long long t[7][14][200000];
int tests;
int Z[20],coef[20][20];
int ps,val;

long long sum(int a,int b,int r)
{
    long long res=0;
    for (;r>=0;r=(r&(r+1))-1)
        res+=t[a][b][r];
    return res;
}

void inc(int a,int b,int i,long long val)
{
    for (;i<200000;i=(i|(i+1)))
        t[a][b][i]+=val;
}

long long sum(int a,int b,int l,int r)
{
    return sum(a,b,r)-sum(a,b,l-1);
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}

for (int i=1;i<=6;i++)
    Z[i]=i*2-2;

for (int z=2;z<=6;z++)
{
    for (int j=1;j<=z*2-2;j++)
        {
            coef[z][j-1]=j%(2*z-2);
            if (coef[z][j-1]>z)
                coef[z][j-1]=2*z-coef[z][j-1];
            if (coef[z][j-1]==0)
                coef[z][j-1]=2;
        }
}

for (int i=0;i<n;i++)
{
    for (int z=2;z<=6;z++)
    for (int rem=0;rem<2*z-2;rem++)
    {
        int trem=i+2*z-2-rem;
        trem%=(2*z-2);
//      cout<<ar[i]*coef[z][trem]<<" "<<i<<" "<<z<<" "<<" "<<rem<<" "<<coef[z][trem]<<endl;
        inc(z,rem,i,ar[i]*1ll*coef[z][trem]);
    }
}

cin>>tests;
for (;tests;--tests)
{
    int tp;
    cin>>tp;
    if (tp==2)
    {
        int l,r,z;
        cin>>l>>r>>z;
        --l;
        --r;
        long long ans=0;

        ans=sum(z,l%(z*2-2),l,r);
        cout<<ans<<endl;
    }
    else
    {
        cin>>ps>>val;
        --ps;
        int dif=val-ar[ps];
        ar[ps]=val;
        for (int z=2;z<=6;z++)
        {
            for (int rem=0;rem<(z*2+2);rem++)
            {
            int trem=ps+z*2-2-rem;
            trem%=(z*2-2);
            inc(z,rem,ps,dif*1ll*coef[z][trem]);
            }
        }
    }
}

//cin.get();cin.get();
return 0;}