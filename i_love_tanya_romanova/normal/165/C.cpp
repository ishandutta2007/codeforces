//#pragma comment(linker, "/STACK:16777216")
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
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long ans,k,ss[3000000],s[3000000];
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>k;getline(cin,st);
getline(cin,st);
for (int i=0;i<st.size();i++)
{s[i+1]=s[i]+(st[i]=='1');
}
for (int i=0;i<=st.size();i++)
ss[s[i]]++;

for (int i=0;i<=1000000;i++)
if (k>0)ans+=ss[i]*ss[i+k];
else if (ss[i]>0)ans+=(ss[i])*(ss[i+k]-1)/2;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}