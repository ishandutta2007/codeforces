/*
You keep on moving
Far away far away
You keep on moving
Far away far away
Everyday wheels are turning
And the cry still returning

Dawn will soon be breaking
The day has just begun
You put your arms around me
Like a circle 'round the sun
Dance across the seasons
To a place that no one knows
Where angels fear to tread
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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long l,r,span,ans;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>l>>r;
span=r-l;

for (int i=0;i<=60;i++)
{
    if ((1ll<<i)<=span)ans+=(1ll<<i);
}
//cout<<ans<<endl;
for (int i=0;i<=60;i++)
{
    if ((1ll<<i)<=span)continue;
    if ((l&(1ll<<i))!=(r&(1ll<<i)))
    ans+=(1ll<<i);
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}