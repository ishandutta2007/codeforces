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
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
char c;
long ar1[1000],ar2[1000],n,m,q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<n;i++)
for (int j=0;j<m;j++)
{cin>>c;
if (c=='*'){ar1[i]++;ar2[j]++;}}

q=0;
while (ar1[q]!=1)++q;
cout<<q+1<<" ";
q=0;
while (ar2[q]!=1)++q;
cout<<q+1<<endl;

cin.get();cin.get();
return 0;}