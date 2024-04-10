#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
vector <long long>v,vv,v1;
long long a,b,c,ans,q;
string d1,d2,d3;
long long trysolve(long long a,long long b,long long c)
{
 for (int i=0;i<4;i++)
 vv[i]=v[i];
 
 for (int i=0;i<a;i++)
 v1[i]=v[i];
 
 if (d1=="*")v1[a]=v[a]*v[a+1];
 
 else v1[a]=v[a]+v[a+1];
 
 for (int i=a+1;i<3;i++)
 v1[i]=v[i+1];

 for (int i=0;i<3;i++)
 v[i]=v1[i];
 
 for (int i=0;i<b;i++)
 v1[i]=v[i];
 
 if (d2=="*")v1[b]=v[b]*v[b+1];
 
 else v1[b]=v[b]+v[b+1];
 
 for (int i=b+1;i<2;i++)
 v1[i]=v[i+1];
 
 for (int i=0;i<2;i++)
 v[i]=v1[i];
 
 if (d3=="*")v1[0]=v[0]*v[1];
 
 else v1[0]=v[0]+v[1];
 
 
 for (int i=0;i<3;i++)
 v[i]=vv[i];
 return v1[0];
 
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
for (int i=1;i<=4;i++)
{cin>>q;v.push_back(q);}

cin>>d1>>d2>>d3;
vv.resize(4);
v1.resize(4);
ans=1000000000;ans*=1000000;

vector <long> vv1;
for (int i=1;i<=4;i++)
vv1.push_back(i);
vector <long> vv2;
for (int i=1;i<=4;i++)
vv2.push_back(v[i-1]);

while (next_permutation(vv1.begin(),vv1.end()))
{
for (int i=0;i<4;i++)
v[i]=vv2[vv1[i]-1];
//for (int i=0;i<4;i++)
//cout<<v[i];
for (int i=0;i<3;i++)
for (int j=0;j<2;j++)
for (int q=0;q<1;q++)
{ans=min(ans,trysolve(i,j,q));
 //cout<<i<<" "<<j<<" "<<q<<" "<<trysolve(i,j,q)<<endl;
}
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}