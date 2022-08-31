/*
Yeah, the way I feel, it seems to me to be so real
So sick and tired, you know just how I feel
The cops, they dress in black, they bid their lives, the bribes they stack
So sick and tired of the same old this and that

The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel

The man who I most resent
You might know him through the government
He'll tax our lives the money's spent, he's just the President
The land of liberty for all mankind and all to see
What's the use of laws of conspiracy

The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel

Searching for answers to make life complete
No need to search for more questions, they're for you to see

The wars that we must fight, you dodge the draft before you drive
So sick and tired, why can't they realize
The rights that they sympathize, life is just a bitter sky
So sick and tried, why can't we live our lives

The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel

The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel
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

long long n,d,k;
vector<long long> vec;
vector<long> ans[1200];

long long gett(long long a,long long b)
{
 long long res=1;
 for (int i=1;i<=b;i++)
 {
  res*=a;
  if (res>n)res=n+1;
 }
 return res;
}

void solve(long x)
{
 --x;
 for (int i=1;i<=d;i++)
 {
  vec.push_back(x%k);
  x/=k;
 }
 for (int i=0;i<d;i++)
  vec[i]++;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>d;
if (gett(k,d)<n)
{
 cout<<-1<<endl;
}
else
{
 for (int i=1;i<=n;i++)
 {
  vec.clear();
  solve(i);
  for (int j=0;j<d;j++)
   ans[j].push_back(vec[j]);
 }

for (int i=0;i<d;i++)
{
 for (int j=0;j<n;j++)
{  if (j)cout<<" ";
  cout<<ans[i][j];}
  cout<<endl;
}

}

cin.get();cin.get();
return 0;}