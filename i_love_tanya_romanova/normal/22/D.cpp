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
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long n,a[10000],b[10000],usd[10000];
long ans;
vector<long> vans;
pair<long, long> p;
pair<pair<long, long> ,long> pp;
vector<pair<pair<long, long> ,long> > v;

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>a[i]>>b[i];
    if (a[i]>b[i])swap(a[i],b[i]);
    
    p=make_pair(b[i],a[i]);
    pp=make_pair(p,i);
    
    v.push_back(pp);
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{if (usd[v[i].second])continue;
ans++;
vans.push_back(v[i].first.first);
long t=v[i].first.first;
for (int j=0;j<n;j++)
if (a[j]<=t&&b[j]>=t)
usd[j]=1;
}

cout<<ans<<endl;
for(int i=0;i<vans.size();i++)
{
        if (i)cout<<" ";
        cout<<vans[i];
        }
        cout<<endl;
        
cin.get();cin.get();
return 0;}