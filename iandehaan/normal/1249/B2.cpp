#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int par[200001];
int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
    if (getPar(x) == getPar(y)) return;
    par[getPar(x)] = getPar(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) par[i] = i;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            Union(i, x);
        }

        int sze[n+1];
        for (int i = 1; i <= n; i++) sze[i] = 0;

        for (int i = 1; i <= n; i++) {
            sze[getPar(i)]++;
        }

        for (int i = 1; i <= n; i++) {
            cout << sze[getPar(i)] << ' ';
        }
        cout << endl;

    }
}