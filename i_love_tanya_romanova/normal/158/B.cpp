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
long n,q,ans,p,ar[20000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;ar[q]++;}
ans=ar[4];
ar[4]=0;
p=ar[3];
ans+=p;
if (ar[1]>p)ar[1]-=p;else ar[1]=0;
ans+=ar[2]/2;ar[2]%=2;
if (ar[2]==1)
{ans++;if (ar[1]>2)ar[1]-=2; else ar[1]=0;}
ans+=ar[1]/4;
ar[1]%=4;
if (ar[1])ans++;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}