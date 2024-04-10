/*
Beyond the dawn, No new day
A ruined mind of false illusion
Beyond the darkness, deeper still
This sorrow has grown so old

Eyes turn skyward
Torn Beyond Reason, far too deep
Broken, Heartless. Void
No words will heal these wounds

Life's touch has faded, all meaning lost
I stride into Death's open arms
The wind will carry no farewell
And so shall the cold soil
Hold the taste of my decay
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
#define right adsgasgadsg

using namespace std;

long n,q,ans1,ans2;
long long ans;
vector<long> v;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 v.push_back(q);
}

sort(v.begin(),v.end());
q=0;
while (q<v.size()&&v[q]==v[0])++q;
ans1=q;
q=v.size()-1;
while (q>=0&&v[q]==v[v.size()-1])--q;
ans2=(v.size()-q-1);
//cout<<ans1<<" "<<ans2<<endl;

cout<<v[v.size()-1]-v[0]<<" ";
if (ans1==n&&ans2==n)
{
 cout<<1ll*n*(n-1)/2<<endl;
}
else cout<<1ll*ans1*ans2<<endl;

cin.get();cin.get();
return 0;}