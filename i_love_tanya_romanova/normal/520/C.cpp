/*
Unrestrained by the illusions
that hold a world at bay
Unbaptized in flames of delusion
For me the world was but a grave

The time is nigh for another revolution
As the sun gives away to greater light
Just a leap in a private evolution
A crop laid out for the reaping,
with a global scythe

Fear not the world falling at your feet
For there are greater things coming to be

The time is ripe for this transformation
As all good talks must come to an end
And where life will greet its negation
And upon this soil no Sun will ever ascend

For I am becoming...
and I'll grow my wings before the fall

As it comes forth from primordial darkness
And takes only what needs to be reclaimed
These slumbering aeons will bear as witness
To the beauty of a world dressed in flame...
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

string st;
long long cnt[1<<20],n,an,mx,ways;
long long ans;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=0;i<st.size();i++)
 cnt[st[i]-'A']++;

ans=1;
for (int i=0;i<26;i++)
 if (cnt[i]>mx)
  mx=cnt[i];

ways=0;
for (int i=0;i<26;i++)
 if (cnt[i]==mx)
  ++ways;

for (int i=1;i<=st.size();i++)
 ans=(ans*ways)%bs;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}