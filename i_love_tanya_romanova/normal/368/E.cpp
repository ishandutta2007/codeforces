/*
Headless
The machine down
Coming to the low sound
Feeling like a real man

Racing
Flashing from down under
Flesh and blood and thunder
Trembling wheel in cold wheel in cold hand

Faster, much faster- wot a human speed disaster
Deeper, much deeper- on through the void I cast'er

I'm a steel tormentor
And I speed 'round ev'ry curve
I'm a mean imperator
Of my intimate machine

Turkey
Near to devastation
Losing all my patience
Cannot make this kit fly

Danger
Muscular contraction
Out for satisfaction
Mere intoxication

Nightride, it's nightride- try to catch my taillights
So sad, I'm so sad, but you won't ever suck my steel bride

I'm a steel tormentor
And I speed 'round ev'ry curve
I'm a mean imperator
Of my intimate machine
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,t,l,r,m,ans,ar[200000];
long long need,x;

long long gett(long long x)
{
 if(x==1)return 1;
 if (x==2)return 2;
 if (x==3)return 4;
 if (x%2)return x*(x-1)/2+1;
 return x*x/2;
// return x*need+2;

}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
while (cin>>x)
cout<<gett(x)<<endl;
*/
cin>>n>>t;
l=1;
r=t;
while (l<r)
{
 m=l+r+1;m/=2;
 if (gett(m)<=n)l=m;
 else r=m-1;
}

for (int i=1;i<=t;i++)
{cin>>ar[i-1];cin>>ar[i-1];}
sort(ar,ar+t);
reverse(ar,ar+t);
for (int i=0;i<l;i++)
ans+=ar[i];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}