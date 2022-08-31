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
long n,ar[2000],q,fl;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int i=1;i<=n;i++)
{q=ar[i];
 if (q>i)
 {
          fl=0;
          for (int j=i;j<=q;j++)
          if (ar[j]!=q-j+i)fl++;
          for (int j=1;j<=n;j++)
          if (ar[j]!=j&&(j<i||j>q))fl++;
          if (fl==0){cout<<i<<" "<<q<<endl;
         return 0; }}
 }
cout<<0<<" "<<0<<endl;
cin.get();cin.get();
return 0;}