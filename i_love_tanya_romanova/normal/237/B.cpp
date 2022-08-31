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
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,c[100000],ar[1000][1000];
pair<long, long> pp;
pair<long ,pair<long, long> > p;
vector < pair<long ,pair<long, long> > > v;
long szz,calc;
long x1[100000],y1[100000],x2[100000],y2[100000];

int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>c[i];
}

for (int i=1;i<=n;i++)
for (int j=1;j<=c[i];j++)
{
    cin>>ar[i][j];
    pp=make_pair(i,j);
    p=make_pair(ar[i][j],pp);
    v.push_back(p);
}

sort(v.begin(),v.end());

calc=-1;

for (int i=1;i<=n;i++)
for (int j=1;j<=c[i];j++)
{
    ++calc;
    v.clear();
    for (int ii=1;ii<=n;ii++)
    for (int jj=1;jj<=c[ii];jj++)
    {pp=make_pair(ii,jj);
    p=make_pair(ar[ii][jj],pp);
    v.push_back(p);}
    
    sort(v.begin(),v.end());
    
    if (v[calc].second.first==i&&v[calc].second.second==j)continue;
    else
    {
        szz++;
        x1[szz]=i;y1[szz]=j;
        x2[szz]=v[calc].second.first;
        y2[szz]=v[calc].second.second;
        swap(ar[i][j],ar[x2[szz]][y2[szz]]);
        
    }
}

cout<<szz<<endl;
for (int i=1;i<=szz;i++)
{
    cout<<x1[i]<<" "<<y1[i]<<" "<<x2[i]<<" "<<y2[i]<<endl;
}
cin.get();cin.get();
return 0;}