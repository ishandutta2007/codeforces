#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define N_ 301000
#define pii pair<int,int>
using namespace std;
int n, w[N_], Res[N_];
vector<int>G[N_];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)G[i].clear();
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        G[w[i]].push_back(i);
    }
    for(i=1;i<=n;i++)Res[i]=-1;
    int pv = n;
    for(i=1;i<=n;i++){
        if(G[i].empty())continue;
        int Mx = 0;
        Mx=max(Mx,G[i][0]);
        Mx=max(Mx,n-G[i].back()+1);
        for(int j=1;j<G[i].size();j++){
            Mx=max(Mx,G[i][j]-G[i][j-1]);
        }
        while(pv>=Mx){
            Res[pv]=i;
            pv--;
        }
    }
    for(i=1;i<=n;i++)printf("%d ",Res[i]);
    puts("");

}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}