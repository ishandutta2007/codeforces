/*
I've been running all my life
Always lost in dreams
Time goes by...
Screams are growing
and night is falling
Beware... the darkness

All I have wanted never is
My world is empty just like me
I won't look back at my own past
I'm living a lie

Time is neverending
Time makes me sigh
Time... I can never find out why it flies

There's no exit
I can't breath
There's no hope for me
Trust no one
Crazy thoughts and
disturbed confessions
drives me insane...
The end is near...

All I have wanted never is
My world is empty just like me
I won't look back at my own past
I'm living a lie
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

long long n,fact[1<<20],invf[1<<20],s,ans;
long long ar[1<<20];

long long pw(long long a,long long b)
{
    if (b==0)return 1;
    if (b%2) return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);
}
long long inv(long long x)
{
    return pw(x,bs-2);
}
long long c(long long n,long long m)
{
    long long res=1;
    res*=fact[n];
    res*=invf[n-m];
    res%=bs;
    res*=invf[m];
    res%=bs;return res;
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=1000000;i++)
{
    fact[i]=fact[i-1]*i%bs;
}

for (int i=0;i<=1000000;i++)
    invf[i]=inv(fact[i]);

cin>>n;
ans=1;

s=0;

for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    ans=ans*c(s+ar[i]-1,ar[i]-1);
    ans%=bs;
    s+=ar[i];
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}