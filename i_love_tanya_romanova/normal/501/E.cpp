/*
An echo on the wind tells a distant warning
Time has come for us to make the journey home
We followed all our lives tales of beasts and valour
And heroes who have walked this road before

If there was another way
If the light can pierce the dark
It seems there's nowhere left to turn
We stand up as one now that our time has come.

Twilight surrounds us the night closes in
Darkness has fallen we stand for our King
An empire in shadows the candle burns low
We'll all find some glory tonight

The chaos in our minds tells a different story
If the light can pierce the dark
Now world will see... see what we are made of
And how we'll conquer all to save the crown

Twilight surrounds us the night closes in
Darkness has fallen we stand for our King
An empire in shadows the candle burns low
We'll all find some glory tonight

If there was another way
If the light can pierce the dark
It seems there's nowhere left to turn
We stand up as one now that our time has come.

We'll all find some glory... tonight.
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,ar[1<<20];
long cnt[1<<20];
vector<long> sub;
long ttl[1<<20],have[1<<20];

long long solve1(vector<long> v)
{
 for (int i=0;i<=n;i++)
  ttl[i]=have[i]=0;
 for (int i=0;i<v.size();i++)
  ttl[v[i]]++;
 
 int mid=-1;
 for (int i=1;i<=n;i++)
  if (ttl[i]%2==1)
   mid=i;
 
 long long res=0;
 
 for (int i=v.size()-1;i+1;--i)
 {
  ++res;
  if (i==v.size()/2&&v.size()%2==1)
  {
   if (v[i]!=mid)return res;
   continue;
  }   
  if (i<v.size()/2)
  {
   if (v[i]!=v[v.size()-i-1])
    return res;
  }
  else
  {
   have[v[i]]++;
   if (have[v[i]]*2>ttl[v[i]])return res;
  }
 }
 return res;
}

long long solve()
{
 for (int i=0;i<=n;i++)
  cnt[i]=0;
 for (int i=1;i<=n;i++)
  cnt[ar[i]]++;
 
 long odd=0;
 for (int i=1;i<=n;i++)
 {
  if (cnt[i]%2)
  {
               if (odd)return 0;
               odd=i;
  }
 }
 
 long l,r;
 l=1;
 r=n;
 while (l<=r&&ar[l]==ar[r])
  ++l,--r;
 
 if (l>r) // all good
 {
  return (1ll*n*(n+1)/2);       
 }
 
 long long ans=1ll*l*(n-r+1);
 
 sub.clear();
 for (int i=l;i<=r;i++)
  sub.push_back(ar[i]);
 
 ans+=l*(solve1(sub)-1);
 //cout<<solve1(sub)<<endl;
 reverse(sub.begin(),sub.end());
 ans+=l*(solve1(sub)-1);
// cout<<solve1(sub)<<endl;
 return ans;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}