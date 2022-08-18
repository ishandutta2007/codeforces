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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long pr[3000000],upp,s[3000000],a,b,k,ans,q;
vector<long> v;
int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

pr[1]=1;

for (int i=2;i<=2000000;i++)
if (pr[i]==0)for (int j=i*2;j<=2000000;j+=i)
pr[j]=1;

s[0]=0;
for (int i=2;i<=1000000;i++)
if (pr[i]==0)v.push_back(i);

cin>>a>>b>>k;

for (int i=1;i<=2000000;i++)
{s[i]=s[i-1];if (pr[i]==0)++s[i];}

for (int i=a;i<=b;i++)
{
    q=s[i-1];
    q+=k-1;
    if (q>=v.size())upp=2000000;
    else upp=v[q];
    upp=min(upp,b+1);
    ans=max(ans,upp-i+1);
//    cout<<i<<" "<<upp<<endl;
}
if (ans>b-a+1)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}