/*
Heaven's waiting for you
Just close your eyes and say goodbye
Hearing your pulse go on and on and on

I live my life in misery
I'd sacrifice this world to hold you
No breath left inside of me
Shattered glass keeps falling

Say
Say goodnight
Just sleep tight
Say goodnight

Flowers laid out for you
So many colors leave me blind
Seeing your face reflect from a babies eyes

I live my life in misery
I'd sacrifice this world to hold you
No breath left inside of me
Shattered glass keeps falling

Say
Say goodnight
Just sleep tight
Say goodnight

So here I am, you're inside of me
So here I am, our worlds may suffer
So here I am, you're inside of me
So here I am, our worlds may suffer

Here I am with you
I'm there till the end
Memories are calling
So farewell my friend
Farewell my friend

Here I am with you
I'm there till the end
Memories are calling
So farewell my friend
Farewell my friend

My friend, my friend, my friend
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

vector<vector<long long> > one(long sz)
{
 vector<vector<long long> > res;
 res.resize(sz);
 for (int i=0;i<res.size();i++)
 {
  res[i].resize(sz);
  for (int j=0;j<res[i].size();j++)
   res[i][j]=(i==j);
 }
 return res;
}

vector<vector<long long> > mult(vector<vector<long long> > a,vector<vector<long long> > b)
{
 vector<vector<long long> > res;
 res=a;
 for (int i=0;i<a.size();i++)
  for (int j=0;j<b.size();j++)
   res[i][j]=0;
 for (int k=0;k<a.size();k++)
  for (int i=0;i<a.size();i++)
   for (int j=0;j<a.size();j++)
    res[i][j]=(res[i][j]+a[i][k]*b[k][j])%bs;
 return res;
}

vector<vector<long long> > pw(vector<vector<long long> > a,long long b)
{
 if (b==0)
  return one(a.size());
  if (b%2) return mult(a,pw(a,b-1));
  return pw(mult(a,a),b/2);
}

long long n,x,q,ar[1<<20],dp[1<<20];

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x;
vector<vector<long long > > v;
v.resize(102);

for (int i=0;i<v.size();i++)
 v[i].resize(102);

for (int i=0;i<v.size();i++)
 for (int j=0;j<v.size();j++)
  v[i][j]=0;

for (int i=0;i+2<v.size();i++)
{
 v[i][i+1]=1;
}

//v[0][v.size()-1]=1;
v[v.size()-1][v.size()-1]=1;
for (int i=0;i<n;i++)
{
 cin>>q;
 ar[i]=q;
 v[q-1][0]++;
 v[q-1][v.size()-1]++;
}

dp[0]=1;

for (int i=0;i<=101;i++)
 for (int j=0;j<n;j++)
 {
  dp[i+ar[j]]=(dp[i+ar[j]]+dp[i])%bs;
 }

vector<long long> vv;
vv.resize(102);
for (int i=0;i<=100;i++)
 vv[100-i]=dp[i],
 vv[101]=(vv[101]+dp[i])%bs;

long long ans=0;
for (int i=0;i<=x&&i<=100;i++)
 ans+=dp[i],
 ans%=bs;
 


long long res=0;

if (x<=100)
 cout<<ans<<endl;
 else{
v=pw(v,x-100);
/*for (int i=0;i<=100;i++)
 cout<<vv[i]<<" "<<" "<<v[i][101]<<endl;*/
// cout<<endl;


for (int i=0;i<102;i++)
 res+=vv[i]*v[i][101],
 res%=bs;

cout<<res<<endl;
}

cin.get();cin.get();
return 0;}