#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Col[210], chk=0, D[210], R[210];
vector<int>E[210];
struct Edge{
    int a, b, ck;
}Ed[4010];
void DFS(int a, int col){
    Col[a]=col;
    for(auto &x : E[a]){
        if(Col[x]==0){
            DFS(x,3-col);
        }
        if(Col[x]+Col[a]!=3){
            chk=1;
        }
    }
}
void Solve(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a, b, ck;
        scanf("%d%d%d",&a,&b,&ck);
        E[a].push_back(b);
        E[b].push_back(a);
        if(ck==1){
            Ed[i] = {a,b,1};
            Ed[m+i] = {b,a,-1};
        }
        else{
            Ed[i] = {a,b,-1};
            Ed[m+i] = {b,a,-1};
        }
    }
    m*=2;
    DFS(1,1);
    if(chk){
        puts("NO");
        return;
    }
    int ans = 0;
    for(int ii=1;ii<=n;ii++){
        for(i=1;i<=n;i++)D[i]=-1e9;
        D[ii]=0;
        for(i=0;i<=n;i++){
            int ck=0;
            for(j=0;j<m;j++){
                int t = D[Ed[j].a] + Ed[j].ck;
                if(D[Ed[j].b]  < t)D[Ed[j].b] = t,ck=1;
            }
            if(ck==1 && i==n){
                puts("NO");
                return;
            }
        }
        int res = 1e9;
        for(i=1;i<=n;i++)res=min(res,D[i]);
        if(ans<= -res){
            ans=-res;
            for(i=1;i<=n;i++){
                R[i]=ans+D[i];
            }
        }
    }
    puts("YES");
    printf("%d\n",ans);
    for(i=1;i<=n;i++)printf("%d ",R[i]);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}