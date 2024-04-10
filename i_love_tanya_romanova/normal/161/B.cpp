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
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,k,c[200000],t[200000];
pair <long, long> p;
vector <pair <long, long> > v1,v2,ans[2000];
double s;
long minc[20000],fl[200000];
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>k;
for (int i=1;i<=n;i++)cin>>c[i]>>t[i];
for (int i=1;i<=n;i++)
{
    if(t[i]==1)
    {p=make_pair(c[i],i);v1.push_back(p);}
    else
    {p=make_pair(c[i],i);v2.push_back(p);}
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());


if (v1.size()<k)
{
                ans[0].push_back(v2[0]);v2.erase(v2.begin());
for (int j=v1.size()+1;j<k;j++)
{ans[j].push_back(v2[0]);v2.erase(v2.begin());                }
}

while (v1.size()>k-1)
{ans[0].push_back(v1[0]);v1.erase(v1.begin());fl[0]=1;
}

for (int i=1;i<=v1.size();i++)
{
   fl[i]=1; ans[i].push_back(v1[i-1]);
}

                             
for (int i=0;i<v2.size();i++)
ans[0].push_back(v2[i]);

s=0;
/*
for (int i=0;i<k;i++)
cout<<fl[i]<<endl;
*/
for (int i=0;i<k;i++)
{
    minc[i]=1100000000;
    for (int j=0;j<ans[i].size();j++)
    {minc[i]=min(minc[i],ans[i][j].first);
     s+=ans[i][j].first;}
     if (fl[i])s-=minc[i]*0.5;
     
}
s+=eps;
cout.precision(1);
cout<<fixed<<s<<endl;

for (int i=0;i<k;i++)
{
cout<<ans[i].size();
for (int j=0;j<ans[i].size();j++)
{cout<<" "<<ans[i][j].second;}
cout<<endl;
}
cin.get();cin.get();
return 0;}