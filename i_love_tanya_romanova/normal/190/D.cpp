/*
I don't walk your path I won't breed that seed
It's deep in my heart though you're my blood
Losing it's deepest bonds crack it's final chains
Unbound the willing from those that are killing

None of the ultimate can save from grace
And here we stand for the final race

Turn from devil's eyes or become his final servant
No way you can hide for it is your destiny
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

long long ans;
long n,k,ar[1<<20];
vector<long> v;
map<long, long> mapp;
long dif;
long cnt,calc[1<<20];
long r;

void add(long x)
{
 calc[x]++;
 if (calc[x]==k)++dif;
}
void del(long x)
{
 calc[x]--;
 if (calc[x]==k-1)--dif;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 v.push_back(ar[i]);
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    if (i==0||v[i]!=v[i-1])
    {
     mapp[v[i]]=cnt;
     ++cnt;
    }
}

for (int i=1;i<=n;i++)
 ar[i]=mapp[ar[i]];

for (int i=1;i<=n;i++)
{
 while (dif<1&&r<=n)
 {
  r++;
  add(ar[r]);
 }
 ans+=(n-r+1);
 del(ar[i]);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}