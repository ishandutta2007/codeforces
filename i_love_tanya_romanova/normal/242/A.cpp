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

long x,y,a,b;
pair<long, long> p;
vector<pair<long, long> > v;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>y>>a>>b;
for (int i=0;i<=x;i++)
for (int j=0;j<=y;j++)
if (i>=a&&j>=b&&i>j)
{
               p=make_pair(i,j);
               v.push_back(p);
}

cout<<v.size()<<endl;
for (int i=0;i<v.size();i++)
cout<<v[i].first<<" "<<v[i].second<<endl;

cin.get();cin.get();
return 0;}