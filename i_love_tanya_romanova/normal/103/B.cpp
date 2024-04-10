#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 aasdfasdfasdf
using namespace std;
long ar[200][200],n,m,q,w,f,arp[2000];
void dfs(long nn)
{arp[nn]=1;
for (int i=1;i<=n;i++){if (arp[i]==0&&ar[nn][i]==1)dfs(i);}
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=m;i++){cin>>q>>w;ar[q][w]=ar[w][q]=1;}
dfs(1);
for (int i=1;i<=n;i++)if (arp[i]==0)f=1;
if (f==0&&m==n)cout<<"FHTAGN!"<<endl; else cout<<"NO"<<endl;

cin.get();cin.get();cin.get();
return 0;
}