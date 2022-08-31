//#pragma comment(linker, "/STACK:16777216")
//#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;

long n,st;
long a,b;
pair<long, long> p;
vector<pair<long, long> > v;
long ans;

int main(){
//freopen("horse.in","r",stdin);
//freopen("horse.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>st>>n;
for (int i=1;i<=n;i++)
{cin>>a>>b;
p=make_pair(a,b);
v.push_back(p);
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    if (v[i].first<st)
    {++ans;st+=v[i].second;
}
}
if (ans==n)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}