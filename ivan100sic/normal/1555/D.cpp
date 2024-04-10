// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
string s;
int z[6][200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> s;
    
    string p = "abc";
    int num = 0;
    do {
        for (int i=0; i<n; i++) {
            z[num][i+1] = z[num][i] + (s[i] != p[i%3]);
        }
        num++;
    } while (next_permutation(begin(p), end(p)));

    while (m--) {
        int l, r, sol = 1e9;
        cin >> l >> r;
        l--;
        for (int i=0; i<6; i++) {
            sol = min(sol, z[i][r] - z[i][l]);
        }
        cout << sol << '\n';
    }
}