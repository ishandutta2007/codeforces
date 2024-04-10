/*
Starving out the many while I only feed the few
Maintain the wealth that keeps me in control of you
Clean on the surface so you won't see my deceit
Even though I'm slithering just beneath your feet
Extend my reign into foreign lands
Flexing my muscle anywhere I can
I keep the power and swallow you whole
Cutting off your life support, I follow through

From way up here my vision's distorted
Cannot maintain what I once supported
I keep you safe, secure and protected
Until my self-indulgence has been perfected

I am the state
I decide your fate
Deliver to all
I bring the downfall

Making up your mind is everything I do
Doing the right thing is never up to you
Get you on board only to betray your trust
I will cut you off when I say you've had enough
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long a,b,m,r,ans[200000],iter;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>m>>r;
for (int i=0;i<m;i++)
 ans[i]=-1;
while (true)
{
 if (ans[r]!=-1)
  {cout<<iter-ans[r]<<endl;return 0;}
 ans[r]=iter;
 ++iter;
 r=r*a+b;r%=m;
}
cin.get();cin.get();
return 0;}