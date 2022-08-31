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
//#define pb push_back
using namespace std;
long x1,x2,fl,y1,y2,n,ans,r[200000],x[200000],y[20000];
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>x1>>y1>>x2>>y2;
if (x1>x2)swap(x1,x2);
if (y1>y2)swap(y1,y2);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>x[i]>>y[i]>>r[i];
}

for (int i=x1;i<=x2;i++)
{fl=0;
 for (int j=1;j<=n;j++)
 {if ((y1-y[j])*(y1-y[j])+(i-x[j])*(i-x[j])<=r[j]*r[j])fl=1;}
 if (fl)ans++;
 fl=0;
 for (int j=1;j<=n;j++)
 {if ((y2-y[j])*(y2-y[j])+(i-x[j])*(i-x[j])<=r[j]*r[j])fl=1;}
 if (fl)ans++;
    }
    
 for (int i=y1+1;i<y2;i++)
 {fl=0;
  for (int j=1;j<=n;j++)
  {if ((x1-x[j])*(x1-x[j])+(i-y[j])*(i-y[j])<=r[j]*r[j])fl=1;}
  if (fl)ans++;
  fl=0;
  for (int j=1;j<=n;j++)
  {if ((x2-x[j])*(x2-x[j])+(i-y[j])*(i-y[j])<=r[j]*r[j])fl=1;}
  if (fl)ans++;
 }
 
 cout<<((y2-y1)+(x2-x1))*2-ans<<endl;
cin.get();cin.get();
return 0;}