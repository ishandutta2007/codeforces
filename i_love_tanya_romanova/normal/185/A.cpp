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
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long long n,r;
long long pw(long long a,long long b)
{
     long long q;
  //   cout<<a<<" "<<b<<endl;
     if (b==0)return 1%bs;
     if (b%2==0)return pw(a*a%bs,b/2);
     else return a*pw(a,b-1)%bs;
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
if (n==0)cout<<1<<endl;
else{
//++n;
r=pw(2,n-1);
r=r%bs;
r*=(1+pw(2,n));
r%=bs;
cout<<r<<endl;
}
cin.get();cin.get();
return 0;}