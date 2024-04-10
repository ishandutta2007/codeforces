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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long ans[200][70][70],d[200][70][70],dd[70][70],n,m,r,a,b,c;

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&r);
//n=m=60;r=0;

for (int i=0;i<m;i++)
for (int j=0;j<n;j++)
for (int q=0;q<n;q++)
scanf("%d",&d[i][j][q]);
//d[i][j][q]=0;


for (int i=0;i<m;i++)
for (int j=0;j<n;j++)
for (int q=0;q<n;q++)
for (int w=0;w<n;w++)
d[i][q][w]=min(d[i][q][w],d[i][q][j]+d[i][j][w]);

/*
for (int i=0;i<m;i++)
{for (int j=0;j<n;j++)
{for (int q=0;q<n;q++)
cout<<d[i][j][q]<<" ";
cout<<endl;}cout<<endl;}*/

for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
dd[i][j]=d[0][i][j];


for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
for (int q=0;q<m;q++)
dd[i][j]=min(dd[i][j],d[q][i][j]);


for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
for (int q=0;q<=n;q++)
ans[q][i][j]=dd[i][j];

    for (int e=0;e<n;e++)
    for (int j=0;j<n;j++)
    for (int q=0;q<n;q++)
    for (int p=0;p<n;p++)
    ans[e+1][j][q]=min(ans[e][j][p]+dd[p][q],ans[e+1][j][q]);

for (int i=0;i<r;i++)
{
    //cin>>a>>b>>c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    --a;--b;
    if (c>n)c=n;
    printf("%d\n",ans[c][a][b]);}
    
cin.get();cin.get();
return 0;}