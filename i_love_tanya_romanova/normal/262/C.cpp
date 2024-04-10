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

long long q[200000],ar[200000],ans[200000],ts[200000];
long long m,n;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m;
for (int i=1;i<=m;i++)
cin>>q[i-1];
sort(q,q+m);
cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];
sort(ar,ar+n);

ans[0]=0;
for (int i=1;i<=n;i++)
ans[i]=1000000000ll*5;

ts[0]=0;
for (int i=1;i<=n;i++)
ts[i]=ts[i-1]+ar[i-1];

long long qq=q[0];

for (int i=0;i<n;i++)
{
 ans[i+1]=min(ans[i+1],ans[i]+ar[i]);
 if (i+qq<=n)
 ans[i+qq]=min(ans[i+qq],ans[i]+ts[i+qq]-ts[i]);
 if (i+qq<=n-1)
 ans[i+qq+1]=min(ans[i+qq+1],ans[i]+ts[i+qq+1]-ts[i+1]);
 if (i+qq<=n-2)
 ans[i+qq+2]=min(ans[i+qq+2],ans[i]+ts[i+qq+2]-ts[i+2]);
}

cout<<ans[n]<<endl;

cin.get();cin.get();
return 0;}