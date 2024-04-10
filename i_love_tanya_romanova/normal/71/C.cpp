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
using namespace std;
long n,w,q,s,fl[200000],tp[200000],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)cin>>tp[i];
for (int q=3;q<=n;q++)
if (n%q==0)
{w=n/q;
 for (int i=0;i<w;i++)fl[i]=0;
 for (int i=1;i<=n;i++)
 {if (tp[i]==0)fl[i%w]=1;}
 s=0;
 for (int i=0;i<w;i++)
 if (fl[i]==0)s=1;
 if (s==1)ans=1;
           }
 if (ans)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 
cin.get();cin.get();
return 0;}