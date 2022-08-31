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

long n,x,ans,q;
long ar1[200000],ar2[200000];

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>x;
for (int i=1;i<=n;i++)cin>>ar1[i-1];
for (int i=1;i<=n;i++)cin>>ar2[i-1];

sort(ar1,ar1+n);
sort(ar2,ar2+n);

q=n-1;
for (int i=0;i<n;i++)
{
    if (ar1[q]+ar2[i]>=x){++ans;--q;}
}
cout<<1<<" "<<ans<<endl;

cin.get();cin.get();
return 0;}