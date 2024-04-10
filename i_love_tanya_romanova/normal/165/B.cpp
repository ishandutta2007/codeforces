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
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,k,l,r,q,m,s;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n>>k;
l=1;
r=1000000000;
while (l<r)
{m=l+r;m/=2;
 q=m;s=0;
 while (q){s+=q;q/=k;}
 if (s<n)l=m+1;else r=m;
      }
      cout<<l<<endl;
cin.get();cin.get();
return 0;}