#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, q;
int cnt[MAXN][26];
string s;

void precompute () {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;
    s = '.' + s;
    precompute();
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        for (int j = 0; j < 26; j++) {
            res += (j + 1) * (cnt[b][j] - cnt[a - 1][j]);
        }
        cout << res << '\n';
    }
    return 0;
}