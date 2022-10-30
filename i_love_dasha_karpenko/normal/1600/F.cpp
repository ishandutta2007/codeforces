//#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 50;
int G[N][N];
ll po[N];
int n,m;
void calc(ll mask){
    vector<int> V;
    int flag = -1;
    for(int bit = 0;bit<n;++bit){
        if (mask&po[bit]){
            if (V.size()==1){
                flag = G[V[0]][bit+1];
            }
            for(int to:V){
                if (G[to][bit+1]!=flag){
                    flag = -2;
                    break;
                }
            }
            if (flag==-2)
                break;
            V.push_back(bit+1);
        }
    }
    if (flag!=-2){
        for(int to:V)
            cout<<to<<' ';
        exit(0);
    }
}
void solve(ll mask,int pos,int need){
    if (need==0){
        calc(mask);
        return;
    }
    if (pos>n)
        return;
    solve(mask+po[pos-1],pos+1,need-1);
    solve(mask,pos+1,need);
}
void solve(){

    cin>>n>>m;
    n = min(n,45);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        if (u>n || v>n)
            continue;
        G[u][v] = G[v][u] = 1;
    }
    solve(0,1,5);

    cout<<"-1\n";
}

signed main() {
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]<<1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;


    while(t--)
        solve();

}