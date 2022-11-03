#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

map<pii, char> g;

int aa = 0;
int ab = 0;

void recalc(int coeff, int u, int v) {
    auto it1 = g.find({u, v});
    auto it2 = g.find({v, u});
    int is_aa = (it1 != g.end() && it2 != g.end() && it1->second == it2->second) ? 1 : 0;
    int is_ab = (it1 != g.end() && it2 != g.end()) ? 1 : 0;
    aa += is_aa * coeff;
    ab += is_ab * coeff;
}

void add(int u, int v, char c) {
    recalc(-1, u, v);
    g[{u, v}] = c;
    recalc(1, u, v);
}

void rem(int u, int v) {
    recalc(-1, u, v);
    g.erase({u, v});
    recalc(1, u, v);
}

bool checkAA() {
    return aa > 0;
}

bool checkAB() {
    return ab > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int u, v, k;
        char c;
        switch (s[0]) {
            case '+':
                cin >> u >> v >> c;
                --u;
                --v;
                add(u, v, c);
                break;
            case '-':
                cin >> u >> v;
                --u;
                --v;
                rem(u, v);
                break;
            case '?':
                cin >> k;
                --k;
                if (k % 2 == 0) {
                    cout << (checkAB() ? "YES" : "NO") << "\n";
                } else {
                    cout << (checkAA() ? "YES" : "NO") << "\n";
                }
                break;
        }
    }



}