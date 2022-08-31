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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,k,q,ans,a,b;
vector <pair <long,long> > v;
pair <long, long> p;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k;

for (int i=0;i<n;i++)
{cin>>a>>b;p=make_pair(-a,b);v.push_back(p);}
sort(v.begin(),v.end());
q=k-1;
while (q>0&&v[q]==v[q-1])--q;
ans=1;
while (q<n-1&&v[q]==v[q+1]){++q;++ans;}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}