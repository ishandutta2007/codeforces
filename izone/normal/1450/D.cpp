#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, w[301000], CK[301000];
vector<int>G[301000];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)G[i].clear();
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        G[w[i]].push_back(i);
    }
    if(G[1].empty()){
        for(i=1;i<=n;i++)printf("0");
        puts("");
        return;
    }
    for(i=1;i<=n+1;i++)CK[i]=0;
    CK[n] = 1;
    int p1 = 1, p2 = n;
    for(i=1;i<n;i++){
        if(G[i].size()==1 && (G[i][0]==p1 || G[i][0]==p2) && !G[i+1].empty()){
            if(G[i][0]==p1)p1++;
            else p2--;
            CK[n-i]=1;
        }
        else break;
    }
    CK[1]=1;
    for(i=1;i<=n;i++)if(G[i].size()!=1)CK[1]=0;
    for(i=1;i<=n;i++)printf("%d",CK[i]);
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}