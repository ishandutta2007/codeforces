#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
//int n, arr[1000005];    
vector<int> conn[1000005];
bool vi[1000005][55];
int id[55][55];

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
int n, m;
string arr[55];
bool have = false;
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
void dfs(int x, int y, int cnt) {
    //cout << x << ' ' << y << ' ' << cnt << '\n';
    if(have) return;
    if(id[x][y] != 0 && cnt - id[x][y] > 2) {
        //cout << x << ' ' << y << ' ' << cnt << '\n';
        have = true;
        return;
    }
    else if(id[x][y] != 0) return;
    id[x][y] = cnt;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < m && arr[x + dx[i]][y + dy[i]] == arr[x][y]) dfs(x + dx[i], y + dy[i], cnt + 1);
    }
}
void solve() {  
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(id[i][j] == 0) dfs(i, j, 1);
    }
    cout << (have ? "Yes\n" : "No\n");
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}