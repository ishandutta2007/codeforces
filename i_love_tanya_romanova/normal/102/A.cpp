#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long n,m,q,w,ar[200][200],ans,c[2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)cin>>c[i];
for (int i=1;i<=m;i++)
{cin>>q>>w;
ar[q][w]=ar[w][q]=1;}
ans=1000000000;
for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
for (int q=j+1;q<=n;q++)
if (ar[i][j]&&ar[j][q]&&ar[q][i])
ans=min(ans,c[i]+c[j]+c[q]);
if (ans>10000000)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;
}