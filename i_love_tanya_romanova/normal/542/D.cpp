/*
Life as we know,
Is full of gloom
Oppress the masses
We'll lead to our doom
We want the right
To live or die
Can't take away
What we feel inside

Like empty shadows,
Afflict our brains
Envision dreams
Just to ease the pain
There's more to life
That to satisfy
I ask myself
For the reason why.

If it were my way
I'd deliver us from this hell
If it were my way.

If ever there comes a day
Renovations blown away
Realize what we've thrown away

Is there no end
To this endless war
The fear of man
In now what's in store.
We look at life as a memory
Long live the dreams
That they took from me.

If it were my way
I'd deliver us from this hell
If it were my way.
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define MAXN 1000

using namespace std;

long long n;
map<long long, vector<long long> > factors;
map<long long, vector<long long> > ::iterator it;
map<long long, long long> dp,ndp;
long long good;
vector<long long> vec;

long long get_prime(long long x)
{
    if (x<2)return -1;
    long long q=-1;
    for (long long p=2;p*p<=x;p++)
        if (x%p==0){q=p;break;}
    if (q==-1)
        q=x;
    while (x%q==0)x/=q;
    if (x==1)return q;
    return -1;
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
if (n==1)
{
    cout<<1<<endl;
    return 0;
}

for (long long i=1;i*i<=n;i++)if (n%i==0)
{
    long long val=get_prime(i-1);
    if (val!=-1)
        factors[val].push_back(i),good++;
    if (i!=n/i)
    {
            val=get_prime(n/i-1);
            if (val!=-1)
             factors[val].push_back(n/i),good++;
    }
}

if (good==0)
{
    cout<<0<<endl;
    return 0;
}

//cout<<good<<endl;

for (it=factors.begin();it!=factors.end();it++)
{
    dp=ndp;
    dp[1]=1;
    vec=(*it).second;
    for (int i=0;i<vec.size();i++)
    {
        for (map<long long, long long>::iterator iter=dp.begin();iter!=dp.end();iter++)
        {
            long long val=(*iter).first;
            if (n/val<vec[i])continue;
            if (n%(vec[i]*val))continue;
            ndp[vec[i]*val]+=dp[val];
        }
    }
}

cout<<ndp[n]<<endl;

//cin.get();cin.get();
return 0;}