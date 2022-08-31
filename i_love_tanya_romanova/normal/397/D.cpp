/*
Nothing like this felt in her kiss, cannot resist her
Fell for her charm, lost in her arms, I keep a photograph
Give me a glimpse, let me come in be there inside her
Here it begins, here is the sin something to lie about

You think you're smart, I think you're art, we agree on this
It doesn't work feeling like dirt, feeling like you don't care
We get a room and in the gloom she lights a cigarette
Clothes on the bed, "Love me", she said, I lose myself to her

I'm getting feelings, I'm hiding too well
(Bury the horse shaped shell)
Something broke inside my stomach
I let the pieces lie just where they fell
(Being with you is hell)

Hair blown in an open car
Summer dress slips down her arm
Hair blown in an open car

Okay what's next? After the sex, what do we now?
Finding the time, drawing the line and never crossing it
Gave her the hours, gave her the power, cannot erase her
Gave her the truth, gave her the proof, I gave her everything

I'm getting feelings, I'm hiding to well
(Bury the horse shaped shell)
Something broke inside my stomach
I let the pieces lie just where they fell
(Being with you is hell)

Hair blown in an open car
Summer dress slips down her arm
Hair blown in an open car
On a drive out to the farm
Hair blown in an open car

Hair blown in an open car
Summer dress slips down your arm
Hair blown in an open car
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long long gcd(long long a,long long b)
{
 if (a<0)a=-a;
 if (b<0)b=-b;
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;    
}

long long lcm(long long a,long long b)
{
 return a/gcd(a,b)*b;
}

pair<long long,long long> ad(pair<long long,long long> p1,pair<long long,long long> p2)
{
long long t=lcm(p1.second,p2.second);
p1.first=p1.first*(t/p1.second)+p2.first*(t/p2.second);
p1.second=t;
t=gcd(t,p1.first);
p1.first/=t;p1.second/=t;
return p1;
}

bool pr(long x)
{
 for (int i=2;i*i<=x;i++)
 if (x%i==0)return false;
 return true;
}

long long tests,n,q,t;
pair<long long, long long> ans;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;

/*ans=ad(make_pair(2,4),make_pair(-1,2));
cout<<ans.first<<" "<<ans.second<<endl;
*/

for (;tests;--tests)
{
 cin>>n;
 long q=n+1;
 t=n+1;
 while (pr(t)==0)++t;
 while (pr(q)==0)--q;
 ans=make_pair(1,2);
 ans=ad(ans,make_pair(-1,q));
// cout<<ans.first<<" "<<ans.second<<endl;
// cout<<n-q+1<<" "<<t*q<<endl;
 ans=ad(ans,make_pair(n-q+1,t*q));
 cout<<ans.first<<"/"<<ans.second<<endl;
}

cin.get();cin.get();
return 0;}