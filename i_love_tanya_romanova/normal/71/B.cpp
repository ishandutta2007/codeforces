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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long long n,k,t,p,s;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k>>t;
p=n*k;
s=0;
while (100*s<=p*t)++s;
--s;
//cout<<s<<endl;
for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";if (s>k){s-=k;cout<<k;}
else {cout<<s;s=0;}
}
cout<<endl;
cin.get();cin.get();
return 0;}