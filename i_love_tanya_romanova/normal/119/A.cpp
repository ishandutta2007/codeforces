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
#define bs 1000000007
using namespace std;
long a,b,q,n,mvs;
long gcd(long a,long b)
{while (a&&b)
{a>b?a%=b:b%=a;}
 return a+b;
}
long move(long n,long r)
{if (r%2==0)
 q=a; else q=b;
 n-=gcd(n,q);return n;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b>>n;
while (n){n=move(n,mvs);++mvs;}
cout<<1-mvs%2<<endl;
cin.get();cin.get();
return 0;
}