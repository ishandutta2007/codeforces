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

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long x,y,z,x1,y1,z1,ar[100000],ans;

int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);


cin>>x1>>y1>>z1;
cin>>x>>y>>z;
for (int i=0;i<6;i++)
cin>>ar[i];

if (y1<0)ans+=ar[0];
if (y1>y)ans+=ar[1];
if (z1<0)ans+=ar[2];
if (z1>z)ans+=ar[3];
if (x1<0)ans+=ar[4];
if (x1>x)ans+=ar[5];

cout<<ans<<endl;
cin.get();cin.get();
return 0;}