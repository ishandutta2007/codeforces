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
#define bs 100000000
//#define szz 400
using namespace std;
long n,m,ans,c;
string c1;
vector <string> v1;
vector <long> v,v2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{cin>>c;v.push_back(c);
}
sort(v.begin(),v.end());
for (int i=1;i<=m;i++){cin>>c1;v1.push_back(c1);}

sort(v1.begin(),v1.end());

c=1;
for (int i=1;i<v1.size();i++)
{if (v1[i]==v1[i-1])++c;
else
{v2.push_back(c);c=1;
}
}

v2.push_back(c);
long ans1=0;
sort(v2.begin(),v2.end());
reverse(v2.begin(),v2.end());
//for (int i=0;i<v2.size();i++)
//{cout<<v2[i]<<" ";}
//for (int i=0;i<v2.size();i++)
//{cout<<v[i]<<" ";}
//cout<<endl;

for (int i=0;i<v2.size();i++)
ans+=v[i]*v2[i];
reverse(v2.begin(),v2.end());
for (int i=0;i<v2.size();i++)
ans1+=v[v.size()-v2.size()+i]*v2[i];
cout<<ans<<" "<<ans1<<endl;
cin.get();cin.get();
return 0;}