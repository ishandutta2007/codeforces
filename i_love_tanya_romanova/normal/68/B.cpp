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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
double ar[10000],l,r,d,m,s1,s2;
long n;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>d;
for (int i=0;i<n;i++)
cin>>ar[i];
l=0;
r=1000000;

while (r>l+eps)
{
      m=l+r;
      m/=2;
      s1=s2=0;
      for (int i=0;i<n;i++)
      
          if (ar[i]>m)s1+=ar[i]-m;
      
      else s2+=m-ar[i];
      
      if (s1*(1.00-0.01*d)>s2)l=m; else r=m;
}

cout.precision(8);
cout<<fixed<<l<<endl;
cin.get();cin.get();
return 0;}