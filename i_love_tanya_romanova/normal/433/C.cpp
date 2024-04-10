/*
Close my eyes, think of the rain
Think of an evening the same
Dream it is autumn outside
An evening to hide

Someone to carry me home
To forests where I do belong
Close my eyes, little bit scared
And no one to care

And then my sun comes down
And you won't hold my hand, it's okay
'Cause when my sun comes down
I'll be walking a darker way, it's okay, it's alright

Close my heart, hold on to evil
Embracing the only, the Foul
Dream it is twilight outside
An evening to hide

Oh raven, say will it be mine
The golden, the line of my time
Fading and I am not scared
Five ravens to bear

And then my sun comes down
And you won't hold my hand, it's okay
'Cause when my sun comes down
I'll be walking a darker way, it's okay
'Cause when my sun comes down
I'll be walking a darker way, it's okay, it's alright
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

long long n,m,ar[200000];
vector<long long> v[200000];
long long ans;
long long s,s1,q;
long long p,done[200000];
long long h,h1;
long long prev;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
prev=-1;
for (int i=1;i<=n;i++){
cin>>ar[i];if (ar[i]==prev)continue;
if (i>1)v[ar[i]].push_back(prev);
if (i>1)v[prev].push_back(ar[i]);
prev=ar[i];}

for (int i=2;i<=n;i++)
 ans+=abs(ar[i]-ar[i-1]);

s=ans;

for (int i=1;i<=n;i++)
{
 if (done[ar[i]])continue;
 q=ar[i];
 done[q]=1;
 h=0;
 for (int j=0;j<v[q].size();j++)
  h+=abs(v[q][j]-q);
 sort(v[q].begin(),v[q].end());
 p=v[q].size()/2;
 h1=0;
 for (int j=0;j<v[q].size();j++)
  h1+=abs(v[q][j]-v[q][p]);
 ans=min(ans,s-h+h1);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}