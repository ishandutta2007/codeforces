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
#pragma comment(linker, "/STACK:16777216")
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;
string st;
long n,fl1,fl2;
vector <char> v1,v2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
cin>>st;
n=st.size();
for (int i=0;i*2<n;i++)
{v1.push_back(st[i]);}
for (int i=n/2;i<n;i++)
{
    v2.push_back(st[i]);
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());

for (int i=0;i<v1.size();i++)
{if (v1[i]<=v2[i])fl1=1;
 if (v1[i]>=v2[i])fl2=1;
}
if (fl1+fl2>1)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
cin.get();cin.get();
return 0;}