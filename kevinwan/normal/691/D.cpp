#include <bits/stdc++.h>
using namespace std;
int k[1000001],p[1000001],cur[1000001];
vector<int> th[1000001];
int find(int x){return (x==p[x])?x:(p[x]=find(p[x]));}
int main() {
    int n,m,i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",k+i),p[i]=i;
    while(m--)scanf("%d%d",&a,&b),p[find(a)]=find(b);
    for(i=1;i<=n;i++)th[find(i)].push_back(k[i]);
    for(i=1;i<=n;i++)sort(th[i].begin(),th[i].end()),cur[i]=th[i].size();
    for(i=1;i<=n;i++)printf("%d ",th[find(i)][--cur[find(i)]]);
}