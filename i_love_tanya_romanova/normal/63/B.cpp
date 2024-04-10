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
long n,k,ans,ar[20000];
bool bd()
{for (int i=1;i<=n;i++)if (ar[i]<k)return true;
 return false;}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k;
for (int i=1;i<=n;i++)cin>>ar[i];
while (bd())
{++ans;
 sort(ar+1,ar+n+1);
 for (int i=n;i>=1;--i)
 if (ar[i]!=ar[i-1])++ar[i];
      }
      cout<<ans<<endl;
cin.get();cin.get();
return 0;}