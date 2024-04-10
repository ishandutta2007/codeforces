// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int T,n,m;
bool used[N];
vector<int> edges;
int main(){
    scanf("%d",&T);
    for(int _case=1;_case<=T;++_case){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            if(!used[u]&&!used[v]){
                used[u]=true;
                used[v]=true;
                edges.push_back(i);
            }
        }
        if(edges.size()>=n){
            puts("Matching");
            for(int i=0;i<n;++i){
                printf("%d ",edges[i]);
            }
            puts("");
        }else{
            puts("IndSet");
            for(int i=1,cnt=0;cnt<n;++i){
                if(!used[i]){
                    printf("%d ",i);
                    ++cnt;
                }
            }
            puts("");
        }
        for(int i=1;i<=n*3;++i){
            used[i]=false;
        }
        edges.clear();
    }
    return 0;
}