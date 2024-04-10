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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 7ll
//#define szz 400
//#define pb push_back
using namespace std;
long n,w,h,answ,par[200000],ans[200000],a,b,ansp;
vector <pair<pair <long, long>, long>  > v;
pair <long, long> p;
pair <pair <long , long> , long> pp;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>w>>h;

for (int i=0;i<=n;i++)
par[i]=-1;

for(int i=1;i<=n;i++)
{
        cin>>a>>b;
        p=make_pair(a,b);
        pp=make_pair(p,i);
        v.push_back(pp);
        sort(v.begin(),v.end());
        }

for (int i=0;i<n;i++)
ans[i]=1;
for (int i=n-1;i+1;--i)
for (int j=i+1;j<n;j++)
{
    if (v[i].first.first<v[j].first.first&&
    v[i].first.second<v[j].first.second)
    {
    if (ans[j]>=ans[i])
    {
                       ans[i]=max(ans[i],ans[j]+1);
                       par[i]=j;
    }}
}
answ=0;
for (int i=0;i<n;i++)
if (ans[i]>answ&&w<v[i].first.first&&h<v[i].first.second)
{answ=ans[i];ansp=i;}
//cout<<ansp<<endl;
vector <long> vv;
cout<<answ<<endl;if (answ)
{
while (ansp!=-1)
{vv.push_back(v[ansp].second);ansp=par[ansp];}
for (int i=0;i<vv.size();i++)
{if (i) cout<<" ";cout<<vv[i];
}
cout<<endl;
}
cin.get();cin.get();
return 0;}