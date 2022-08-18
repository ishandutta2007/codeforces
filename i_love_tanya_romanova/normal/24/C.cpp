//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long long x[1000000],y[1000000],a,b,n,m;
long long q;
int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
cin>>a>>b;

for (int i=0;i<n;i++)
{
 cin>>x[i]>>y[i];   
}

m%=(n*10);
for (int i=1;i<=m;i++)
{
    q=i-1;
    q%=n;
    a=2*x[q]-a;
    b=2*y[q]-b;
}
cout<<a<<" "<<b<<endl;

cin.get();cin.get();
return 0;}