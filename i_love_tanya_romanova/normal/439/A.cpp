/*
In his arms, locked in that iron grip nothing will reveal
Follow these footsteps and we will reach the bottom

I tumbled down the road that bears his name
Here he dwells, here he prospers and pushes us towards the end

When we are drifting against the tide 
Colliding with the very air we breathe 
Somewhere the tracks inwards must lead out
A grasp of hope that defeats the will

Always pushed away
Always nothing
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,d,t[200000],need,ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d;
for (int i=0;i<n;i++)
 cin>>t[i];

for (int i=0;i<n;i++)
{
 need+=t[i];
 if (i>0)need+=10;
 if (i>0)ans+=2;
}
if (need>d)cout<<-1<<endl;
else {
     d-=need;
     ans+=d/5;
     cout<<ans<<endl;
}
cin.get();cin.get();
return 0;}