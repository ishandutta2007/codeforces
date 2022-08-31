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
#define EPS 1e-9
#pragma comment(linker, "/STACK:16777216")
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;
long n,ar[20000],ans,ss,s;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)cin>>ar[i-1];
sort(ar,ar+n);
for (int i=0;i<n;i++)
s+=ar[i];
for (int i=n-1;i+1;--i)
{if (ss*2<=s){ans++;}ss+=ar[i];}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}