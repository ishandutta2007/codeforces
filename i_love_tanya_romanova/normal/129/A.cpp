#include <iostream>
//#include <fstream>
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
#define szz 400
using namespace std;
long ar[200],s,n,q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)cin>>ar[i];
for (int i=0;i<n;i++){s+=ar[i];}
for (int i=0;i<n;i++)if ((s-ar[i])%2==0)ans++;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}