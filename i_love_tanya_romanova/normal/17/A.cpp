#include <iostream>
//#include <fstream>
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
#define szz 400
using namespace std;
vector <long> v;
long pr[20000],a,b,ans,fl;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
pr[1]=1;
for (int i=2;i<=1000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000;j+=i)
pr[j]=1;
for (int i=2;i<=1000;i++)
if (pr[i]==0)v.push_back(i);

cin>>a>>b;
for (int i=1;i<=a;i++)
if (pr[i]==0)
{fl=0;
 for (int j=0;j<v.size()-1;j++)
 {if (v[j]+v[j+1]+1==i)fl=1;}
             if (fl)ans++;}
if (ans>=b)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}