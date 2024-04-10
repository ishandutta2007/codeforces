/*
Utopia lost in chaos
As the sky turns black
Suicidal legacy
There is no turning back, no turning back

Retribution answers cold
Moving in for the kill
Deep hideous festering
Bestial epidemic, repulsive need

Control, control

Suicide nation
Mass-appeal, death-addiction
Dead but dreaming
Restrained by phobia, brainwashed into submission

Control, control

Suicide, suicide
Suicide, suicide
Jaws locked around your spine
Locked around your spine

Retribution answers cold
Moving in for the kill
Deep hideous festering
Bestial epidemic, repulsive need

Control, control

Suicide, suicide
Suicide, suicide
Jaws locked around your spine
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
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long long fact[1<<20],pW[1<<20],n,k;
string st;
long long s[1<<20];
long long val1,ways1;

long long pw(long long a,long long b)
{
 if (b==0) return 1;
 if (b%2) return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

long long c(long long n,long long m)
{
 if (m<0||m>n)return 0;
 long long res=1;
 res*=fact[n];
 res*=inv(fact[m]);
 res%=bs;
 res*=inv(fact[n-m]);
 return res%bs;
}

long long ans,ways2;
long long val2;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
fact[0]=1;
for (int i=1;i<=100000;i++)
{
 fact[i]=fact[i-1]*i%bs;   
}

pW[0]=1;
for (int i=1;i<=200000;i++)
 pW[i]=pW[i-1]*10%bs;
 
cin>>st;
for (int i=1;i<=st.size();i++)
 s[i]=s[i-1]+(st[i-1]-48);

if (k==0)
{
 long long val=0;
 for (int i=0;i<st.size();i++)
  val=val*10+st[i]-48,
  val%=bs;
 cout<<val<<endl;
 return 0;
}

for (int p=1;p<=n;p++)
{
 val1=s[n-p];
 val1*=pW[p-1];
 val1%=bs;
 ways1=c(n-p-1,k-1);
 ans+=ways1*val1%bs;
// cout<<ans<<endl;
 val2=s[n-p+1]-s[n-p];
 val2*=pW[p-1];
 val2%=bs;
 ways2=c(n-p,k);
 ans+=val2*ways2%bs;
 ans%=bs;
// cout<<ans<<endl;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}