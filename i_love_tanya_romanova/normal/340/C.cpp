/*
Lost again
Broken and weary
Unable to find my way
Tail in hand
Dizzy and clearly unable to
Just let this go

I am surrendering to gravity and the unknown
Catch me heal me lift me back up to the sun
I choose to live

I fell again
Like a baby unable to stand on my own
Tail in hand
Dizzy and clearly unable to just let this go
High and surrendering to gravity and the unknown
Catch me heal me lift me back up to the sun
I choose to live, I choose to live, I choose to live

Catch me heal me lift me back up to the sun
Help me survive the bottom

Calm these hands before they
Snare another pill and
Drive another nail down another
Needy hole please release me

I am surrendering to gravity and the unknown
Catch me heal me lift me back up to the sun
I choose to live, I choose to live
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

vector<long long> v;
long long n,q,ans,dsum;

long long gcd(long long a,long long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;v.push_back(q);
}

sort(v.begin(),v.end());


for (int i=0;i<v.size();i++)
{
 ans+=1ll*v[i]*i-dsum;
 dsum+=v[i];   
// cout<<ans<<" "<<dsum<<endl;
}
ans*=2;
for (int i=0;i<v.size();i++)
ans+=v[i];

/*
reverse(v.begin(),v.end());
dsum=0;
for (int i=0;i<v.size();i++)
{
 ans+=dsum-1ll*v[i]*i;
 dsum+=v[i];
 cout<<ans<<" "<<dsum<<endl;
}
*/
long long q=gcd(ans,n);
cout<<ans/q<<" "<<n/q<<endl;
cin.get();cin.get();
return 0;}