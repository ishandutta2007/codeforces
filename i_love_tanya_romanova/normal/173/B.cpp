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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,e,v[200000],d[21000],arp[21000],g[200000];
char ar[1200][1200];
vector <long> r[2100];
queue<long> q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>ar[i][j];
}

for (int i=1;i<=n+m;i++)
{
    v[i]=g[i]=100000;
}

g[n]=0;

for (int i=n;i;--i)
for (int j=m;j;--j)
{
    if (ar[i][j]=='#')
    {
             
             r[i].push_back(j+1000);
             r[j+1000].push_back(i);
                 //v[j]=min(v[j],g[i]+1);
                 //g[i]=min(g[i],v[j]+1);
    }
}

for (int i=1;i<=2000;i++)
d[i]=0;
for (int i=1;i<=2000;i++)
arp[i]=0;

long w;
q.push(n);
while (q.size())
{
      w=q.front();q.pop();
      arp[w]=1;
      for (int i=0;i<r[w].size();i++)
      {
          e=r[w][i];if (arp[e]==0){arp[e]=1;d[e]=d[w]+1;q.push(e);}
      }
}
      
if (arp[1]==0)d[1]=-1;
cout<<d[1]<<endl;

cin.get();cin.get();
return 0;}