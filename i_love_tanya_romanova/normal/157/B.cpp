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
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,r[200000],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
cin>>r[i];
sort(r+1,r+n+1);
for (int i=1;i<=n;i++)
if (i%2==n%2)ans+=r[i]*r[i]-r[i-1]*r[i-1];
cout.precision(5);
cout<<fixed<<ans*M_PI<<endl;
cin.get();cin.get();
return 0;}