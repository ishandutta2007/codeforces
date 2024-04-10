#include<bits/stdc++.h>
using namespace std;
// #define int long long

const int MAXN = 1e5 + 5, SQRT = 316;

vector<int> S[MAXN], occ[MAXN];
long long sum[MAXN], lz[MAXN];
int inc[MAXN][SQRT + 21];
bool chk[MAXN];
vector<int> up;

long long a[MAXN];
int n, m, q;

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1, k; i <= m; i++){
        cin >> k;
        S[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> S[i][j];
            occ[S[i][j]].push_back(i);
            sum[i] += a[S[i][j]];
        }
        if (k > SQRT){
            up.push_back(i);
            chk[i] = 1;
        }
    }
    for (int k = 0; k < up.size(); k++){
        for (auto v : S[up[k]]){
            for (auto y : occ[v]){
                inc[y][k] ++;
            }
        }
    }
    while(q--){
        char s;
        cin >> s;
        if (s == '+'){
            int k;
            long long x; 
            cin >> k >> x;
            if (chk[k]){
                lz[k] += x;
            }else{
                for (auto v : S[k]){
                    a[v] += x;
                }
                for (int i = 0; i < up.size(); i++){
                    sum[up[i]] += (long long) x * inc[k][i];
                }
            }
        } else {
            int k;
            long long ans = 0;
            cin >> k;
            if (chk[k]){
                ans += sum[k];
            }else{
                for (auto v : S[k]){
                    ans += a[v];
                }
            }
            for (int i = 0; i < up.size(); i++){
                ans += (long long) lz[up[i]] * inc[k][i];
            }
            cout << ans << endl;
        }
    }
}