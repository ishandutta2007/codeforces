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
long n,ar[200],ps;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)cin>>ar[i-1];
sort(ar,ar+n);
ps=1;
while (ps<n&&ar[ps]==ar[ps-1])++ps;
if (ps>=n)cout<<"NO"<<endl; else cout<<ar[ps]<<endl;
cin.get();cin.get();

return 0;}