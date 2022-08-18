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

#define y0 sdkfaslhagaklsldk
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

long p,n,m,calc[200000],a,b,ar[200000];
vector<long> ans,g[200000];
queue<long> qu;


int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

for (int i=1;i<=n;i++)
{
    cin>>calc[i];
    if (calc[i]==0)
    qu.push(i);
}

while (qu.size())
{
  a=qu.front();
  qu.pop();
  ans.push_back(a);
  ar[a]++;
  
  for (int i=0;i<g[a].size();i++)
  {
   p=g[a][i];
   ar[p]++;
   if (ar[p]==calc[p])
   {
                      qu.push(p);
   }   
  }   
}

cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cin.get();cin.get();
return 0;}