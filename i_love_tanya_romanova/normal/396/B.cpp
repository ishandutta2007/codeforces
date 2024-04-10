/*
You keep me waiting
You keep me alone in a room full of friends
You keep me hating
You keep me listening to the Bends

No amount of pointless days
Can make this go away

You have me on my knees
You have me listless and deranged
You have me in your pocket
You have me distant and estranged

No narcotics in my brain
Can make this go away

I'm sorry that, I'm sorry that I'm not like you
I worry that I don't act the way you'd want me to

You find me wanting
You find me bloodless but inspired
You find me out
You find me hallucinating fire

No narcotics in my brain
Can make this go away

Have we ever been here before?
Running headlong at the floor
Leave me dreaming on a railway track
Wrap me up and send me back
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