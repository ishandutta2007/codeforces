#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10;
vi con[N];
int Parity, freq[2][N * 200], xorsum[2], A[N], FREQ[2];
void dfs(int s, int p, int parity){
    int cnt = 0;
    freq[parity][A[s]]++;
    xorsum[parity] ^= A[s];
    FREQ[parity]++;
    for(int v : con[s]){
        if(v != p){
            cnt++;
            dfs(v, s, parity ^ 1);
        }
    }
    if(cnt == 0) Parity = parity;
}
int main(){
    int n; sd(n);
    for(int i = 1; i <= n; i++) sd(A[i]);
    for(int i = 2; i <= n; i++){
        int p;
        sd(p);
        con[p].pb(i);
        con[i].pb(p);
    }
    dfs(1, 0, 0);
    ll ans = (xorsum[Parity] == 0 ? (FREQ[0] * 1ll * (FREQ[0] - 1) + FREQ[1] * 1ll * (FREQ[1] - 1)) / 2 : 0);
    for(int i = 0; i < N * 100; i++) ans += freq[Parity][i] * 1ll * freq[Parity ^ 1][i ^ xorsum[Parity]];
    printf("%lld", ans);
}