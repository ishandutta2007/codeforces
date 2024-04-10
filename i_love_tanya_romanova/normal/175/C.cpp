
//#pragma comment(linker, "/STACK:16777216")
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
#define  INF 1000000000
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,t,pp,k[200000],c[20000],mul,ans,a,b,cc;
vector <long long> v1;
pair <long long, long long> p;
vector <pair <long long, long long> > v;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;
for (int i=1;i<=n;i++){
cin>>k[i]>>c[i];
p=make_pair(c[i],k[i]);v.push_back(p);}
sort(v.begin(),v.end());

cin>>t;
for (int i=1;i<=t;i++)
{cin>>pp;v1.push_back(pp);}
v1.push_back(100000000000000ll);
for (int i=v1.size()-1;i>0;i--)
v1[i]-=v1[i-1];

mul=1;
while (v.size()>0)
{
      a=v[0].first;
      b=v[0].second;
      cc=v1[0];
      if (b<cc)
      {ans+=b*a*mul;v1[0]-=b;v.erase(v.begin());}
      else
      {ans+=cc*a*mul;mul++;v1.erase(v1.begin());v[0].second-=cc;
      if (v[0].second==0)v.erase(v.begin());}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}