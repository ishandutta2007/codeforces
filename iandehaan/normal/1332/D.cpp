#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll par[200001];
ll findPar(int x) {
    if (par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void Union(int x, int y) {
    if (findPar(x) == findPar(y)) return;
    par[findPar(x)] = par[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;
    cout << 3 << ' ' << 3 << endl;
    ll strt = 1;
    while (strt <= k) {
        strt <<= 1;
    }
    strt += k;
    cout << strt << ' ' << k << ' ' << 0 << endl;
    cout << strt-k << ' ' << k << ' ' << 0 << endl;
    cout << strt << ' ' << strt << ' ' << k << endl;
}