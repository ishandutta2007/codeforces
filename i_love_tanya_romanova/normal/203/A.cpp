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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
#define MAXN 1000000

long x,t,a,b,da,db,fl;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>t>>a>>b>>da>>db;
for (int i=0;i<t;i++)
for (int j=0;j<t;j++)
{if (a-da*j+b-db*i==x)fl=1;
 if (a-da*j==x)fl=1;
 if (b-db*i==x)fl=1;
 if (0==x)fl=1;
}
if (fl)cout<<"YES"<<endl; else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}