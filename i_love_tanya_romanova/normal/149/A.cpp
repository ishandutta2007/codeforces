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
//#define bs 7ll
//#define szz 400
//#define pb push_back
using namespace std;
long n,k,ans,s,ar[200];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>k;
for (int i=0;i<12;i++)cin>>ar[i];
sort(ar,ar+12);
ans=-1;
s=0;
for (int i=11;i>=0;i--)
{if (s>=k&&ans==-1)ans=11-i;
s+=ar[i];if (s>=k&&ans==-1)ans=11-i+1;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}