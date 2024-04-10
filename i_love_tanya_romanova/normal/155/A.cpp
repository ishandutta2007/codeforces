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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,fl1,fl2,ans,ar[200000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)cin>>ar[i];
for (int i=2;i<=n;i++)
{
    fl1=fl2=0;
    for (int j=1;j<i;j++)
    {if (ar[j]<=ar[i])fl1=1;
     if (ar[j]>=ar[i])fl2=1;
    }
    if (fl1+fl2==1)ans++;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}