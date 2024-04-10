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
long n,p,ans,ar[2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=7;i++)cin>>ar[i];
p=1;
while (n>0)
{ans++;n-=ar[p];p++;if (p>7)p=1;}
if (p==1)p=7; else --p;
cout<<p<<endl;
cin.get();cin.get();
return 0;}