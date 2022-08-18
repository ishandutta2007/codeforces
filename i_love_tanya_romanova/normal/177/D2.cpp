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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m,k,ar1[200000],s[200000],ar2[200000],l,r,c;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>m;
cin>>k;

for (int i=1;i<=n;i++)
cin>>ar1[i];

for (int i=1;i<=m;i++)
cin>>ar2[i];

for (int i=1;i<=m;i++)
s[i]=s[i-1]+ar2[i];

for (long i=1;i<=n;i++)
{
    r=min(i,m);
    l=max(1+m-m,m-(n-i));
    ar1[i]=ar1[i]+s[r]-s[l-1];
    ar1[i]%=k;
}
for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";
cout<<ar1[i];}
cout<<endl;

cin.get();cin.get();
return 0;}