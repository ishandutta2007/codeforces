/*
Nature stands erected
The season of the Sun
Gather around the stones
The time for blot has come

Light the fires of the north
Bring forth the goblets
A toast to our fortune
To Freya, Frey and fortune

Come lust for ecstasy
Unleash the seal of man
Come lust for ecstasy
It is Midsummer's Eve

Morbid spirits rising
Essence of the night
They sing a song of blasphemy
The demons dance tonight

Light the fires of the north
Bring forth the goblets
A toast to our fortune
To Freya, Frey and fortune

Come lust for ecstasy
Unleash the seal of man
Come lust for ecstasy
It is Midsummer's Eve
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
#define bsize 512
#define nice adsfasdfasdfasdf

using namespace std;

long long h,w,n,dp[1<<20];
vector<pair<long long, long long> > v;
long long fact[1<<20],invf[1<<20];

long long pw(long long a,long long b)
{
    if (b==0)
        return 1;
    if (b%2)
        return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);  
}
long long inv(long long x)
{
    return pw(x,bs-2);
}

long long c(long long n,long long m)
{
    if (m>n)
        return 0;
    long long res=fact[n];
    res*=invf[m];
    res%=bs;
    res*=invf[n-m];
    return res%bs;
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=300000;i++)
    fact[i]=fact[i-1]*i%bs;

for (int i=0;i<=300000;i++)
    invf[i]=inv(fact[i]);

cin>>h>>w>>n;
for (int i=1;i<=n;i++)
{
    int a,b;
    
    cin>>a>>b;
    v.push_back(make_pair(a,b));
}

v.push_back(make_pair(1,1));
v.push_back(make_pair(h,w));

sort(v.begin(),v.end());

dp[0]=1;
n=v.size();

for (int i=1;i<v.size();i++)
{
//  cout<<i<<endl;
    dp[i]=c(v[i].first+v[i].second-2,v[i].first-1);
    for (int j=1;j<i;j++)
    {
        if (v[j].first<=v[i].first&&v[j].second<=v[i].second)
        {
            long long temp=c(v[i].first-v[j].first+v[i].second-v[j].second,v[i].first-v[j].first);
            temp=temp*dp[j]%bs;
            dp[i]=dp[i]+bs-temp;
            dp[i]%=bs;
        }
    }
}
cout<<dp[n-1]<<endl;

//cin.get();cin.get();
return 0;}