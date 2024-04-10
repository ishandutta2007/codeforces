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

long n,k,t[200000],d[200000],ans,best[20][100000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>k;

for (int i=1;i<=n;i++)
{cin>>t[i]>>d[i];
//p=make_pair(t[i],d[i]);
//v.push_back(p);
}
++n;
t[n]=86401;
d[n]=1;

best[0][0]=0;

for (int i=1;i<=n;i++)
{
    
 for (int j=0;j<=k;j++)
 best[i%10][j]=0;
 
 for (int j=0;j<=k;j++)
 {
  ans=max(ans,t[i]-best[(i+9)%10][j]-1);
  if (best[(i+9)%10][j]<t[i])
  {
   best[i%10][j]=t[i]+d[i]-1;
  }
  else best[i%10][j]=best[(i+9)%10][j]+d[i];
  if (j>0)
  {
          best[i%10][j]=min(best[i%10][j],best[(i+9)%10][j-1]);
  }
 }
}


cout<<ans<<endl;


cin.get();cin.get();
return 0;}