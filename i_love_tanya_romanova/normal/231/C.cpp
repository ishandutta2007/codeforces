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

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long long n,k,ansp,s[200000],ar[200000],l,r,ans;

int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}
sort(ar,ar+n);
for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i-1];
l=1;
r=1;
while (r<=n)
{
      while (ar[r-1]*(r-l+1)+s[l-1]-s[r]>k)++l;
      if (ans<r-l+1)
      {ans=r-l+1;ansp=r;}++r;
      
}

cout<<ans<<" "<<ar[ansp-1]<<endl;

cin.get();cin.get();
return 0;}