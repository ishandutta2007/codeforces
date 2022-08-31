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
vector <long> v;
long n,a[200000],b[200000],s,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;

for (int i=1;i<=n;i++)
{cin>>a[i]>>b[i];}

s=1;
for (int i=1;i<=n;i++)
{if (b[i]>0)
{s+=b[i]-1;ans+=a[i];}
}

for (int i=1;i<=n;i++)
{if (b[i]==0)
{v.push_back(a[i]);
    }}

sort(v.begin(),v.end());
for (int i=v.size();i>long(v.size())-s&&i>0;i--)
ans+=v[i-1];
cout<<ans<<endl;
cin.get();cin.get();
return 0;}