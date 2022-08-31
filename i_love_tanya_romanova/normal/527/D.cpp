/*
I wandered through the forest blind
The Golden Land I searched so hard to find
Lay in ruins beneath the soul I left so far behind
Lost somewhere within the sands of time
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
I could feel your warmth and light
When cold and darkness filled the sky
Your words became a shining path that led me through the night
"The land you seek has always been, it lies within"
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
I found comfort in your truth
Solace in your words
The kingdom we seek lies within
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
#define count adsgasdgasdg

using namespace std;

long n,a,b,ans,r;
vector<pair<long, long> > v;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a+b,a-b));
}
sort(v.begin(),v.end());

r=-2e9;
for (int i=0;i<v.size();i++)
{
 if(v[i].second>=r)
 {
  r=v[i].first;
  ++ans;
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}