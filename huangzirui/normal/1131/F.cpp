#include <bits/stdc++.h>
using namespace std;
int fa[200010];
vector<int>e[200010];
int i,j,k,n,m;
int main() {
    cin>>n;
	for(i=1;i<=n;i++){
        fa[i]=i;
        e[i].push_back(i);
    }
	for(i=1;i<n;i++){
		int x,y,t1,t2;
        scanf("%d%d",&x,&y);
        if (e[fa[x]].size()<=e[fa[y]].size())swap(x,y);
        t1=fa[x],t2=fa[y];
        for (j=0;j<e[t2].size();j++) {
            e[t1].push_back(e[t2][j]);
            fa[e[t2][j]]=t1;
        }
        e[t2].clear();
    }
    for(i=1;i<=n;i++)printf("%d ",e[fa[1]][i-1]);
    return 0;
}