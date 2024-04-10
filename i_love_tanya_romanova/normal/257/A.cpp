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

long sz[1000],n,m,k,ans,tans;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
{cin>>sz[i];--sz[i];sz[i-1]=sz[i];}

sort(sz,sz+n);
reverse(sz,sz+n);

tans=k;
for (int i=0;i<n;i++)
tans+=sz[i];

ans=10000000;

if (tans<m)ans=-1;

for (long i=0;i<n;i++)
{
    if (k>=m)ans=min(ans,i);
 k+=sz[i];
 if (k>=m)
 ans=min(ans,i+1);
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}