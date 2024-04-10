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
long n,ans;
vector <string> v;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;getline(cin,st);
for (int i=0;i<n;i++)
{getline(cin,st);v.push_back(st);
}
sort(v.begin(),v.end());
ans=1;
for (int i=1;i<v.size();i++)
if (v[i]!=v[i-1])ans++;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}