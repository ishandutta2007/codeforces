#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define next osidfjoisd

const int maxn = 251;
const int maxlen = 1e5 + 10;

int n, q;
int dp[maxn][maxn][maxn];
int next[maxlen][26];
vector<int> a[3];
int len[3];

template<class T>
void chmin(T& a, T b) {
    a = min(a, b);
}

void update_first() {
    int L = sz(a[0]) - 1;
    for (int x = 0; x <= len[1]; ++x) {
        for (int y = 0; y <= len[2]; ++y) {
            int temp = dp[L][x][y];
            dp[L + 1][x][y] = next[temp][a[0].back()];
        }
    }
    for (int x = 0; x <= len[1]; ++x) {
        for (int y = 0; y <= len[2]; ++y) {
            int temp = dp[L + 1][x][y];
            if (x < len[1]) {
                chmin(dp[L + 1][x + 1][y], next[temp][a[1][x]]);
            }
            if (y < len[2]) {
                chmin(dp[L + 1][x][y + 1], next[temp][a[2][y]]);
            }
        }
    }
}

void update_second() {
    int L = sz(a[1]) - 1;
    for (int x = 0; x <= len[0]; ++x) {
        for (int y = 0; y <= len[2]; ++y) {
            int temp = dp[x][L][y];
            dp[x][L + 1][y] = next[temp][a[1].back()];
        }
    }
    for (int x = 0; x <= len[0]; ++x) {
        for (int y = 0; y <= len[2]; ++y) {
            int temp = dp[x][L + 1][y];
            if (x < len[0]) {
                chmin(dp[x + 1][L + 1][y], next[temp][a[0][x]]);
            }
            if (y < len[2]) {
                chmin(dp[x][L + 1][y + 1], next[temp][a[2][y]]);
            }
        }
    }
}

void update_third() {
    int L = sz(a[2]) - 1;
    for (int x = 0; x <= len[0]; ++x) {
        for (int y = 0; y <= len[1]; ++y) {
            int temp = dp[x][y][L];
            dp[x][y][L + 1] = next[temp][a[2].back()];
        }
    }
    for (int x = 0; x <= len[0]; ++x) {
        for (int y = 0; y <= len[1]; ++y) {
            int temp = dp[x][y][L + 1];
            if (x < len[0]) {
                chmin(dp[x + 1][y][L + 1], next[temp][a[0][x]]);
            }
            if (y < len[1]) {
                chmin(dp[x][y + 1][L + 1], next[temp][a[1][y]]);
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> q;
    string s;
    cin >> s;
    for (int j = 0; j < 26; ++j) {
        next[n][j] = n + 1;
        next[n + 1][j] = n + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            next[i][j] = next[i + 1][j];
        }
        next[i][s[i] - 'a'] = i + 1;
    }
    
    for (int it = 0; it < q; ++it) {
        string tp, ch;
        int id;
        cin >> tp >> id;
        --id;
        if (tp == "-") {
            a[id].pop_back();
        } else {
            cin >> ch;
            a[id].push_back(ch[0] - 'a');
            
            for (int i = 0; i < 3; ++i) {
                len[i] = sz(a[i]);
            }
            
            if (id == 0) {
                update_first();
            } else if (id == 1) {
                update_second();
            } else {
                update_third();
            }
        }
        
        if (dp[sz(a[0])][sz(a[1])][sz(a[2])] <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}