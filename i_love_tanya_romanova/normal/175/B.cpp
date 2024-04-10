
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
pair <string, long> p;
vector <pair <string, long> > v,v1;
long a,q,s,n;
string st;
double ps[2000];
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;
for (int i=0;i<n;i++)
{
    cin>>st;
    cin>>a;
    p=make_pair(st,-a);
    v.push_back(p);
}

sort(v.begin(),v.end());

v1.push_back(v[0]);
for (int i=1;i<v.size();i++)
if (v[i].first!=v[i-1].first)v1.push_back(v[i]);

for (int i=0;i<v1.size();i++)
v1[i].second=-v1[i].second;

cout<<v1.size()<<endl;
for (int i=0;i<v1.size();i++)
{
    q=v1[i].second;s=0;
    for (int j=0;j<v1.size();j++)
    if (v1[j].second<=q)s++;
    ps[i]=s*1.0/v1.size()*100+1e-8;
}

for (int i=0;i<v1.size();i++)
{
    cout<<v1[i].first<<" ";
    if (ps[i]<50)cout<<"noob";
    else if (ps[i]<80)cout<<"random";
    else if (ps[i]<90)cout<<"average";
    else if (ps[i]<99)cout<<"hardcore";
    else cout<<"pro";
    cout<<endl;
}
cin.get();cin.get();
return 0;}