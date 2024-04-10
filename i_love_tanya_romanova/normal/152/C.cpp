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
string st;
long long a,s,b,ar[2000][2000],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;
for (int i=1;i<=a;i++)
{cin>>st;
 for (int j=0;j<b;j++)
 {ar[j+1][st[j]]=1;
 }
}
ans=1;
for (int i=1;i<=b;i++)
{
    s=0;
    for (int j=1;j<=200;j++)
    s+=ar[i][j];
    ans*=s;
    ans%=bs;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}