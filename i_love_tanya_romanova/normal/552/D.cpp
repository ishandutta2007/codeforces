/*
Trapped in purgatory
A lifeless object, alive
Awaiting reprisal
Death will be their acquisition

The sky is turning red
Return to power draws near
Fall into me, the sky's crimson tears
Abolish the rules made of stone

Pierced from below, souls of my treacherous past
Betrayed by many, now ornaments dripping above

Awaiting the hour of reprisal
Your time slips away

Raining blood
From a lacerated sky
Bleeding its horror
Creating my structure
Now I shall reign in blood!
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

int n,x[5000],y[5000];
map<pair<int,pair<int, int> > ,int> cnt;
pair<int,pair<int, int> > tp;
long long trip;
int a,b,c;
int gcd(int a,int b)
{
    if (a<0)a*=-1;
    if (b<0)b*=-1;
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>x[i]>>y[i];
}

for (int orig=1;orig<=n;orig++)
{
    cnt.clear();
    for (int i=1;i<=n;i++)
     if (i!=orig)
     {
        a=y[i]-y[orig];
        b=x[orig]-x[i];
        c=-a*x[i]-b*y[i];
        long q=gcd(a,gcd(b,c));
        a/=q;
        b/=q;
        c/=q;
        if (a<0||a==0&&b<0||a==0&&b==0&&c<0)
            a*=-1,
            b*=-1,
            c*=-1;
        tp=make_pair(a,make_pair(b,c));
        trip+=cnt[tp];
        cnt[tp]++;
     }
}

long long ans=1ll*n*(n-1)*(n-2)/6;
ans-=trip/3;
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}