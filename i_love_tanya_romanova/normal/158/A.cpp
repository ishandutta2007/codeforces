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
long n,k,p;
vector <long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k;
for (int i=1;i<=n;i++)
{cin>>p;v.push_back(-p);}
sort(v.begin(),v.end());

while (k>0&&v[k-1]==0)--k;

if (k>0)
while (k<n&&v[k-1]==v[k]&&v[k]<0)k++;
cout<<k<<endl;
cin.get();cin.get();
return 0;}