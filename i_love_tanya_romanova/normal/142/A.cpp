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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long long n,ans1,ans2;
vector <long long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
ans2=1000000000;
ans2*=ans2;
for (long long i=1;i*i<=n;i++){
if (n%i==0){v.push_back(i);v.push_back(n/i);}}
for (long long j=0;j<v.size();j++)
{long long t=n/v[j];
 for (long long q=1;q*q<=t;q++)if (t%q==0){ans1=max(ans1,(v[j]+1)*(q+2)*(t/q+2)-(v[j])*(q)*(t/q));
ans2=min(ans2,(v[j]+1)*(q+2)*(t/q+2)-(v[j])*(q)*(t/q));
}}
cout<<ans2<<" "<<ans1<<endl;
cin.get();cin.get();
return 0;}