#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;
const int MOD = 1000000007;

int n, m;
int par[MAXN], cap[MAXN];
vector <int> v;

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int tip, a, b;
        cin >> tip;
        if (tip == 1) {
            cin >> a;
            a = nadi(a);
            if (cap[a] == 0) {
                cap[a] = 1;
                v.push_back(i);
            }
        } else {
            cin >> a >> b;
            a = nadi(a); b = nadi(b);
            if (a == b) continue;
            if (cap[a] == 1) {
                if (cap[b] == 0) {
                    cap[b] = 1;
                    v.push_back(i);
                }
            } else if (cap[b] == 1) {
                if (cap[a] == 0) {
                    cap[a] = 1;
                    v.push_back(i);
                }
            } else {
                par[min(a, b)] = max(a, b);
                v.push_back(i);
            }
        }
    }
    int pot = 1, siz = v.size();
    for (int i = 0; i < siz; i++) {
        pot = pot * 2 % MOD;
    }
    cout << pot << " " << siz << '\n';
    for (auto x : v) cout << x << " ";
    return 0;
}