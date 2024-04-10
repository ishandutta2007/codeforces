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

long long pr[2000000],n,a,ans;
vector<long long> v;

long long gcd(long long a,long long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

pr[1]=1;
for (int i=2;i<=1000000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000000;j+=i)
pr[j]=1;

cin>>n;
if (n<=1000000)
{
          ans=0;
          
          for (long long i=n-100;i<=n;i++)
          for (long long j=n-100;j<=n;j++)
          for (long long q=n-100;q<=n;q++)
          if (i>0&&j>0&&q>0)
          {
              a=i*j/gcd(i,j);
              a=a*q/gcd(a,q);
              ans=max(ans,a);
          }
          cout<<ans<<endl;
}
/*
else
{
    for (int i=1;i<=n;i++)
    if (pr[i]==0)v.push_back(i);
    ans=v[v.size()-1]*v[v.size()-2]*v[v.size()-3];
}
cout<<ans<<endl;
*/
cin.get();cin.get();
return 0;}