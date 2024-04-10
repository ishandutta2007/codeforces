/*
I met a girl who hated the world - she used her body to sell her soul
Everytime they'd break her and pay - tear out her heart, and leave her in pain
I never found out how she survived all of the sadness she kept inside
I never found out how she could lie with a smile on her face,
and the scratches she'd hide

[Chorus:]
You could love her if you paid, you could have her everyday
You could love her if you prayed, you could have her every way

Down on her knees, she wept on the floor - this hopeless life she wanted no more
Dead in her mind and cold to the bone - she opened her eyes and saw she was alone
She never found out how much I tried - all of the sadness she kept made me blind
She never found out how much I cried - the rope so tight on the night that she died...

[Chorus]

I never found out how she survived - a life lived in lies is a life of denial
I never found out how she could lie - with a smile on her face and the darkness inside

[Chorus x2]
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

vector<long long> a;
long long c[1000][1000];
long long sz,n,m;
vector<vector<long long> > v;

vector<long long> mult(vector<long long> a,vector<vector<long long> > b)
{
 vector<long long> res;
 res.resize(a.size());
 for (int i=0;i<res.size();i++)
 res[i]=0;
 for (int i=0;i<a.size();i++)
  for (int j=0;j<b.size();j++)
   res[j]+=a[i]*b[i][j],res[j]%=bs;
 return res;
}

vector<vector< long long> > mult(vector<vector< long long> > a,vector<vector<long long> > b)
{
 vector<vector<long long> > res;
 res.resize(a.size());
 for (int i=0;i<res.size();i++)
 res[i].resize(a.size());
 
 for (int i=0;i<a.size();i++)
  for (int j=0;j<a.size();j++)
   res[i][j]=0;
   
 for (int k=0;k<a.size();k++)
 for (int i=0;i<a.size();i++)
  for (int j=0;j<b.size();j++){
   res[i][j]+=a[i][k]*b[k][j];res[i][j]%=bs;}
 return res;
}

vector<vector<long long> > one(long sz)
{
 vector<vector<long long> > r;
 r.resize(sz);
 for (int i=0;i<r.size();i++) r[i].resize(sz);
 for (int i=0;i<r.size();i++)
  for (int j=0;j<r.size();j++)
   if (i==j)r[i][j]=1;else r[i][j]=0;
 return r;
}

vector<vector<long long> > pw(vector<vector< long long> > a,long long b)
{
 if (b==0)return one(a.size());
 if (b%2)return mult(a,pw(a,b-1));
 return pw(mult(a,a),b/2);
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

c[0][0]=1;

for (int i=1;i<=50;i++)
{
 for (int j=0;j<=i;j++)
  if (j==0||j==i)
  c[i][j]=1;
  else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;
}
/*
for (int i=0;i<=5;i++)
 {
  for (int j=0;j<=i;j++)
  cout<<c[i][j]<<" ";
  cout<<endl;
 }
 */
sz=m*2+3;
a.resize(sz);
v.resize(sz);
for (int i=0;i<v.size();i++)
v[i].resize(a.size());

for (int i=0;i<a.size();i++)
 for (int j=0;j<a.size();j++)
  {v[i][j]=0;a[i]=0;}
 
 
for (int i=0;i<sz-1;i++)
a[i]=1;
v[sz-2][sz-1]=v[sz-1][sz-1]=1;
for (int i=0;i<=m;i++)
 for (int j=i;j<=m;j++)
  v[i][j+m+1]=v[i+m+1][j]=v[i+m+1][j+m+1]=c[j][i];

v=pw(v,n);
a=mult(a,v);
/*
for (int i=0;i<sz;i++)
cout<<a[i]<<" ";
cout<<endl;
*/
cout<<a[sz-1]<<endl;

cin.get();cin.get();
return 0;}