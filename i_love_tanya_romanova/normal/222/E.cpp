/*
I don't deserve you, why can't you see
I will desert you, why don't you leave
But you put your faith in me one last time
You, you put your faith in love all the time
I don't deserve you, why can't you see
I will desert you, why don't you leave
But you put your faith in me one last time
You, you put your faith in love all the time

I believe that you, you and me, you and me
We, we've achieved a love that we, we can see

I don't deserve you, why can't you see
I will desert you, why don't you leave
But you put your faith in me one last time
You, you put your faith in love all the time

I believe that you, you and me, you and me
We, we've achieved a love that we, we can see
For, I believe that you, you and me, you and me
We, we've achieved a love that we, we can see

So go find your path, take me with you
I will make sure no one hurts you
I need your ways, we deserve it
We'll depend on our love here we
Go find your path, take me with you
I will make sure no one hurts you
I need your ways, we deserve it
We'll depend on our love here we go
Here we go
You know, you know

For, I believe that you and me
We've achieved a love we can see
My love
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long long n,m,k,a,b;
vector<vector<long long> > zr;
string st;
long long ans;

vector<vector<long long> > getone()
{
 vector<vector<long long> > res;
 res.resize(m);
 for (int i=0;i<res.size();i++)
 res[i].resize(m);
 for (int i=0;i<m;i++)
  for (int j=0;j<m;j++)
  res[i][j]=(i==j);
 return res;
}

long parse(char c)
{
 if (c>='a'&&c<='z')return c-'a';
 return c-'A'+26;
}

vector<vector<long long> > mult(vector<vector<long long> > v1,vector<vector<long long> > v2)
{
 vector<vector<long long> > v3;
 v3=v1;
 
 for (int i=0;i<v1.size();i++) 
  for (int j=0;j<v1.size();j++)
   v3[i][j]=0;
 
 for (int k=0;k<m;k++)
  for (int i=0;i<m;i++)
   for (int j=0;j<m;j++)
   {
       v3[i][j]+=v1[i][k]*v2[k][j];
       v3[i][j]%=bs;
   }
  return v3;
}

vector<vector<long long> > pw(vector<vector<long long> > v,long long pwr)
{
 if (pwr==0)return getone();
 if (pwr%2)return mult(v,pw(v,pwr-1));
 return pw(mult(v,v),pwr/2);
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
zr=getone();

for (int i=0;i<zr.size();i++)
 for (int j=0;j<zr.size();j++)
  zr[i][j]=1;
  
for (int i=1;i<=k;i++)
{
  cin>>st;
  a=parse(st[0]);b=parse(st[1]);
  zr[a][b]=0;  
}

zr=pw(zr,n-1);

for (int i=0;i<zr.size();i++)
for (int j=0;j<zr.size();j++)
ans+=zr[i][j];

/*
for (int i=0;i<zr.size();i++)
{
    for (int j=0;j<zr.size();j++)
    cout<<zr[i][j]<<" ";
    cout<<endl;
}
*/

cout<<ans%bs<<endl;

cin.get();cin.get();
return 0;}