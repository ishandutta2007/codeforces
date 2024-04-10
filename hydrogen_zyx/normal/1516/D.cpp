#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100005;
int phi[N], prime[N], cnt;
bool st[N];

void get_eulers() {
    phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; prime[j] * i < N; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
}

int nxt[N][20];
int a[N];
int vis[N];

vector<int> fen(int x) {
    vector<int> ans;
    for (int i = 0; prime[i] * prime[i] <= x; i++) {
        if (x % prime[i] == 0) {
            ans.push_back(prime[i]);
            while (x % prime[i] == 0) x /= prime[i];
        }
    }
    if (x != 1) ans.push_back(x);
    return ans;
}

int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a);
        b >>= 1;
        a = (a * a);
    }
    return ans;
}


vector<int> v[N];

int main() {
    get_eulers();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i] = fen(a[i]);

    }
//    for (int i = 1; i <= n; i++) {
//        for (auto x: v[i]) cout << x << ' ';
//        cout << endl;
//    }
    int pos = 1;
    for (auto x: v[1]) {
        vis[x]++;
    }
    for (int i = 2; i <= n; i++) {
        int chong = 0;
        for (auto x:v[i]) {
            vis[x]++;
            if (vis[x] > 1) chong++;
        }
        while (chong) {
            for (auto x:v[pos]) {
                vis[x]--;
                if (vis[x] == 1) chong--;
            }
            nxt[pos][0] = i;
            pos++;
        }
    }
    while (pos <= n) {
        nxt[pos][0] = n + 1;
        pos++;
    }
//    for (int i = 1; i <= n; i++) cout << nxt[i][0] << ' ';
//    cout << endl;
    nxt[n + 1][0] = n + 1;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n + 1; j++) {
            nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int now = l;
        for (int i = 19; i >= 0; i--) {
            if (nxt[now][i] <= r) {
                ans += qpow(2, i);
                now = nxt[now][i];
            }
        }
        ans++;
        cout << ans << endl;
    }
}