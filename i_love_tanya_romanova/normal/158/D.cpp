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
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long ans,n,q,ar[500][21000];
vector <long long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int j=3;j<=n;j++)
if (n%j==0)v.push_back(n/j);


for (int i=1;i<=n;i++)
{cin>>q;
 for (int j=0;j<v.size();j++)
 ar[j][i%v[j]]+=q;}

ans=-1000000000;
for (int i=0;i<v.size();i++)
{for (int j=0;j<v[i];j++)
 ans=max(ans,ar[i][j]);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}