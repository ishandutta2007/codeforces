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

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,q,sz;
vector<long>ans[1000];

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
cin>>n;
q=n-1;

while (q){sz++;q/=2;}

cout<<sz<<endl;
for (int i=0;i<n;i++)
{for (int j=0;j<sz;j++)
if (i&(1<<j))ans[j].push_back(i+1);
}
for (int i=0;i<sz;i++)
{cout<<ans[i].size();
for (int j=0;j<ans[i].size();j++)
cout<<" "<<ans[i][j];
cout<<endl;}


cin.get();cin.get();
return 0;}