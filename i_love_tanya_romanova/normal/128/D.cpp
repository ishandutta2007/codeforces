/*
I woke up, can't wait to eat
Got my cereal, boy was I beat
Opened the fridge and to my dismay
There was no milk, my mother will pay

I want some milk
My coffee grows cold
I want some milk
I should've been told

Oh, I wish I had some goddamn milk
My Cheerios just ain't the same
I wish I had some goddamn milk
Too bad the milkman never came

I can't go out to the store
I'll just wait 'til mommy buys more
I'll just have wheat thins and beer
If I get sick the toilet's near

I want some milk
My coffee grows cold
I want some milk
I should've been told

Oh, I wish I had some goddamn milk
My Cheerios just ain't the same
I wish I had some goddamn milk
Too bad the milkman never came, yeah yeah

I want some milk
My coffee grows cold
I want some milk
I should've been told
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

long n,ar[200000],calc;
vector<pair<long, long> > vec;

bool solve(vector<pair<long, long> > vec)
{
 for (int i=1;i<vec.size();i++)
  if (vec[i].second!=vec[i-1].second+1)return false;
 long rem=0;
 rem=vec[0].first*2;
 for (int i=1;i<vec.size();i++)
 {
  if (rem<=0)return false;
  rem=vec[i].first*2-rem;
//  cout<<rem<<" "<<vec[i].first<<"  "<<vec[i].second<<endl;
 }
 if (rem)return false;
 return true;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i-1];
}
sort(ar,ar+n);

for (int i=0;i<n;i++)
{
 if (i>0&&ar[i]>ar[i-1]){vec.push_back(make_pair(calc,ar[i-1]));calc=1;}
 else ++calc;
}

vec.push_back(make_pair(calc,ar[n-1]));

if (solve(vec))cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}