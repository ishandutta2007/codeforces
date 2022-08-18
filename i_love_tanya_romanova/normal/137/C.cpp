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
long n,tp,ans,a,b;
pair <long, long> p;
vector  <pair <long, long> > v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>a>>b;p=make_pair(a,b);
 v.push_back(p);}
sort(v.begin(),v.end());
tp=0;
for (int i=0;i<v.size();i++)
{if (v[i].second<tp)ans++;else tp=v[i].second;}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}