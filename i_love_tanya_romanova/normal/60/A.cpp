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
long n,m,s,ar[20000],p;
string st,st1;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=m;i++)
{cin>>st1;cin>>st1; cin>>st1; cin>>st; cin>>p;
 if (st1[0]=='l')for (int j=p;j<=n;j++)ar[j]=1;
 if (st1[0]=='r')for (int j=1;j<=p;j++)ar[j]=1;}
s=0;
for (int i=1;i<=n;i++)if (ar[i]==0)s++;
if (s==0)--s;
cout<<s<<endl;
cin.get();cin.get();
return 0;}