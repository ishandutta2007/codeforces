//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,k,t,r,s,ar[1000],a[1000],b[1000],q;
long c[100][100];
vector<long> v;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k>>t;

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
c[i][j]=-1;

for (int i=1;i<=k;i++)
{
    cin>>a[i]>>b[i];
    cin>>c[a[i]][b[i]];
}

r=n+1;
for (int i=2;i<=n;i++)
r*=(n+1);

for (int mask=0;mask<r;++mask)
{
 q=mask;
    
 for (int i=1;i<=n;i++)   
 {
     ar[i]=q%(n+1);q/=(n+1);
 }
 s=0;
 for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 if (ar[i]==ar[j]&&ar[i]>0)
 s=-1000000000;
 
 for (int i=1;i<=n;i++)
 {
  if (ar[i]>0)
  if (c[i][ar[i]]>-1)
  s+=c[i][ar[i]];
  else s=-1000000000;   
 }
 
 if (s>=0)
 v.push_back(s);
}

sort(v.begin(),v.end());
//for (int i=0;i<v.size();i++)
//cout<<v[i]<<" ";
//cout<<endl;

cout<<v[t-1]<<endl;

cin.get();cin.get();
return 0;}