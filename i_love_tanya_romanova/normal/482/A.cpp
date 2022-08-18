/*
Oh, I rule the jungle, I rule it with pride
I'm judge and jury, your life I decide
I have awakened for my nightly feast
A reign of terror, beware of the beast

Don't try to run, there's no way to survive
A vicious surrender, I'll eat you alive
No one is safe until I get my fill
All hear my warning, I'm King of the Kill

Stalking the lend for the scent of my prey
Starving for nothing, don't get in my way
Left to the vultures, your life is denied
I rule the jungle, I rule it with pride

Don't try to run, there's no way to survive
A vicious surrender, I'll eat you alive
No one is safe until I get my fill
All hear my warning, I'm King of the Kill

Don't try to run, there's no way to survive
A vicious surrender, I'll eat you alive
No one is safe until I get my fill
All hear my warning, I'm King of the Kill

Don't try to run, there's no way to survive
A vicious surrender, I'll eat you alive
No one is safe until I get my fill
All hear my warning, I'm King of the Kill, Kill

Oh, King of the Kill, yeah, Kill
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
#define free adsgasdg

using namespace std;

long n,k,up,dwn;
vector<long> ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

if (k%2==0)// dwn
{
 up=dwn=n-k/2;
 ++up;
 --dwn;
 ans.push_back(up-1);
 for (int i=1;i<=k;i++)
 {
  if (i%2){ans.push_back(up);++up;}
  else {ans.push_back(dwn);--dwn;}
 }
 for (int i=k+2;i<=n;i++)
  ans.push_back(n-i+1);
}
else
{
 up=dwn=k/2+1;
 ++up;
 --dwn;
 ans.push_back(up-1);
 for (int i=1;i<=k;i++)
 {
  if (i%2){ans.push_back(up);++up;}
  else {ans.push_back(dwn);--dwn;}
 }
 for (int i=k+2;i<=n;i++)
  ans.push_back(i);
}
 for (int i=0;i<ans.size();i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
cin.get();cin.get();
return 0;}