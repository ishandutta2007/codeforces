//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,a,b,ll,rr,c;
pair<long, long> p;
pair<pair<long, long>, long> pp;
vector<pair<pair<long, long> ,long> >  v;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

ll=1000000000;
cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 rr=max(rr,b);
 ll=min(ll,a);
 p=make_pair(a,-b);
 pp=make_pair(p,i);
 v.push_back(pp);   
}
sort(v.begin(),v.end());

a=v[0].first.first;
b=-v[0].first.second;
c=v[0].second;
if (a==ll&&b==rr)
cout<<c<<endl;
else cout<<-1<<endl;

cin.get();cin.get();
return 0;}