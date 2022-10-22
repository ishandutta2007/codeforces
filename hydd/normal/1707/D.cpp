//
// Created by hydd on 2022/7/17.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,Mod,f[2100][2100],C[2100][2100];
ll pre[2100][2100],suf[2100][2100],Ans[2100];
vector<int> vec[2100];
void dfs(int u,int fa){
    if (fa) vec[u].erase(find(vec[u].begin(),vec[u].end(),fa));
    int len=(int)vec[u].size()-1;
    for (int i=0;i<=len;i++){
        int v=vec[u][i];
        dfs(v,u);
    }
    for (int i=0;i<=len;i++){
        int v=vec[u][i]; ll s=0;
        for (int j=1;j<=n;j++){
            s=(s+f[v][j])%Mod;
            pre[i][j]=s; suf[i][j]=s;
        }
    }
    for (int i=1;i<=len;i++)
        for (int j=1;j<=n;j++)
            pre[i][j]=pre[i-1][j]*pre[i][j]%Mod;
    for (int j=1;j<=n;j++) f[u][j]=(len>=0?pre[len][j]:1);
    for (int i=len-1;i>=0;i--)
        for (int j=1;j<=n;j++)
            suf[i][j]=suf[i+1][j]*suf[i][j]%Mod;
    if (fa){
        for (int i=0;i<=len;i++){
            int v=vec[u][i]; ll s=0;
            for (int j=1;j<=n;j++){
                f[u][j]=(f[u][j]+f[v][j]*s)%Mod;
                s=(s+(i?pre[i-1][j]:1)*(i+1<=len?suf[i+1][j]:1))%Mod;
            }
        }
    }
}
int main(){
    cin>>n>>Mod; int u,v;
    for (int i=1;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    for (int i=0;i<n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    for (int i=1;i<n;i++){
        Ans[i]=f[1][i];
        for (int j=0;j<i;j++) Ans[i]=(Ans[i]+1ll*(Mod-Ans[j])*C[i][j])%Mod;
        cout<<Ans[i]<<' ';
    }
    return 0;
}