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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long x[20000],n,y[2000],a,b,c,d,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;

for (int i=0;i<n;i++)
{cin>>x[i]>>y[i];}

for (int i=0;i<n;i++)
{
    a=b=c=d=0;
    for (int j=0;j<n;j++)
    if (x[j]==x[i]&&y[j]<y[i])a++;
    for (int j=0;j<n;j++)
    if (x[j]==x[i]&&y[j]>y[i])b++;
    for (int j=0;j<n;j++)
    if (y[i]==y[j]&&x[i]<x[j])c++;
    for (int j=0;j<n;j++)
    if (y[i]==y[j]&&x[i]>x[j])d++;
    if (a&&b&&c&&d)ans++;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}