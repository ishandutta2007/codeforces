#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int dsu[1005];
int f(int x) {
    if(dsu[x] == x) return x;
    return dsu[x] = f(dsu[x]);
}
set<int> edge[1005];
set<int> member[1005];
bool vi[1005];
int col[1005];
void dfs(int now) {
    // cout << now << '\n';
    vi[now] = true;
    for(auto x: edge[now]) {
        if(!vi[x]) {
            col[x] = col[now] ^ 1;
            dfs(x);
        }
    }
}
void merge(int a, int b, bool change) {
    if(a == b) return;
    if(f(a) != f(b)) {
        if(member[a].size() < member[b].size()) {
            for(auto x: member[a]) {
                col[x] ^= change;
                member[b].insert(x);
            }
            dsu[a] = b;
        }
        else {
            for(auto x: member[b]) {
                col[x] ^= change;
                member[a].insert(x);
            }
            dsu[b] = a;
        }
    }
}
void solve(int TC) {
    int n;
    cin >> n;
    int arr[n + 5][n + 5];
    for(int i = 1; i <= n; i++) {
        dsu[i] = i;
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
        edge[i].clear();
        member[i].clear();
        member[i].insert(i);
        vi[i] = false;
    }
    for(int i = 0; i <= n; i++) col[i] = -1;
    // col[1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // cout << i << ' ' << j << '\n';
            // for(int k = 0; k < n; k++) cout << f(k) << " \n"[k == n - 1];

            if(arr[i][j] < arr[j][i]) {
                int a = f(i);
                int b = f(j);
                if(a == b) continue;
                if(col[i] == -1 && col[j] == -1) {
                    col[i] = col[j] = 0;
                    merge(a, b, false);
                }
                else if(col[i] == -1) {
                    col[i] = col[j];
                    merge(a, b, false);
                }
                else if(col[j] == -1) {
                    col[j] = col[i];
                    merge(a, b, false);
                }
                else if(col[i] != col[j]) {
                    merge(a, b, true);
                }
                else merge(a, b, false);
            }
            else if(arr[i][j] > arr[j][i]) {
                int a = f(i);
                int b = f(j);
                if(a == b) continue;
                if(col[i] == -1 && col[j] == -1) {
                    col[i] = col[j] = 0;
                    merge(a, b, true);
                }
                else if(col[i] == -1) {
                    col[i] = col[j];
                    merge(a, b, true);
                }
                else if(col[j] == -1) {
                    col[j] = col[i];
                    merge(a, b, true);
                }
                else if(col[i] != col[j]) {
                    merge(a, b, false);
                }
                else merge(a, b, true);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        // cout << f(i) << '\n';
        // if(f(i) != i) continue;
        if(col[i] == -1) {
            // cout << i << '\n';
            col[i] = 0;
            // dfs(i);
        }
    } 
            // for(int k = 0; k < n; k++) cout << f(k) << " \n"[k == n - 1];
    // for(int i = 0; i < n; i++) cout << col[i + 1] << " \n"[i == n - 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(col[i] ^ col[j]) cout << arr[j][i];
            else cout << arr[i][j];
            cout << " \n"[j == n];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}