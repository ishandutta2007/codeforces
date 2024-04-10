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
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long n,e,s,ss;
long gcd(long a,long b)
{while (a&&b)a>b?a%=b:b%=a;
 return a+b;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (long bs=2;bs<n;bs++)
{e=n;
 while (e){ss+=e%bs;e/=bs;}}
cout<<ss/gcd(ss,n-2)<<"/"<<(n-2)/gcd(ss,n-2)<<endl;
cin.get();cin.get();
return 0;}