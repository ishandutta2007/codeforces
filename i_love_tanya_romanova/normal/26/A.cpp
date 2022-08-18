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
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
string st;
long pr[240000],n,q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
pr[1]=1;
for (int i=2;i<=100000;i++)
if (pr[i]==0)
{for (int j=i*2;j<=100000;j+=i)
pr[j]=1;
             }
cin>>n;
for (int i=1;i<=n;i++)
{q=0;
 for (int j=1;j<=i&&q<3;j++)
 {if (pr[j]==0&&i%j==0)q++;}
 if (q==2)ans++;}
 cout<<ans<<endl;

cin.get();cin.get();
return 0;
}