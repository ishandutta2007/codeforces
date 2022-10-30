#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e5+5;
vector<int> arr[maxn];
int val[maxn];
bool vis[maxn];
int main(){
    int i,j,k,n,m;
    int u,v,cnt;
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (i=1;i<=n;i++) if (arr[i].size()<n-1){
        puts("YES");
        for (j=0;j<arr[i].size();j++)
            vis[arr[i][j]]=true;
        for (j=1;j<=n;j++) if (j!=i&&!vis[j]){
            val[i]=1; val[j]=2; cnt=3;
            for (k=1;k<=n;k++) if (val[k]==0)
                val[k]=cnt++;
            for (k=1;k<=n;k++) printf("%d ",val[k]);
            puts("");
            val[j]=1;
            for (k=1;k<=n;k++) printf("%d ",val[k]);
            puts("");
            return 0;
        }
    }
    puts("NO");
    return 0;
}