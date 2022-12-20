#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e9;
const int N = 3e5 + 13;
vector<int> e[N];

struct def {
    string color[2];
    int changelock = -1;
};

vector<def> m;

def merg(def left, def right) {
    def ans = left;
    if (right.changelock != -1)
        ans.changelock = right.changelock;
    if (left.changelock == -1) {
        for (int j = 0; j < 2; ++j)
            if (right.color[j] != "") {
                ans.color[j] = right.color[j];
            }
    } else {
        for (int j = 0; j < 2; ++j)
            if (right.color[left.changelock] != "") {
                ans.color[j] = right.color[left.changelock];
            }
    }
    return ans;
}

def get(string s) {
    def ans;
    ans.changelock = -1;
    ans.color[0] = "";
    ans.color[1] = "";
    if (s == "unlock")
        ans.changelock = 0;
    else if (s == "lock") {
            ans.changelock = 1;
        } else {
            ans.color[0] = s;
        }
    return ans;
}


void build(int v, int vl, int vr, vector<string>& s) {
    if (vr - vl == 1) {
        m[v] = get(s[vl]);
    } else {
        build(2*v+ 1, vl, (vl + vr) / 2, s);
        build(2*v + 2, (vl + vr) / 2, vr, s);
        m[v] = merg(m[2*v + 1], m[2*v + 2]);
    }
}

void als(int v, int vl, int vr, int pos, string s) {
    if (vl >= pos + 1 || pos >= vr)
        return;
    if (vr - vl == 1) {
        m[v] = get(s);
    } else {
        als(2*v + 1, vl, (vl + vr) / 2, pos, s);
        als(2*v + 2, (vl + vr) / 2, vr, pos, s);
        m[v] = merg(m[2*v + 1], m[2*v + 2]);
    }
}
void solve() {
    int n, k,a, b;
    string s;
    cin >> n;
    vector<string> v(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    m.resize(4 * v.size());
    build(0, 1, n + 1, v);
    int q;
    cin >> q;
    if (m[0].color[0] == "")
        cout << "blue\n";
    else
        cout << m[0].color[0] << "\n";
    for (int i = 0; i < q; ++i) {
        string s;
        int pos;
        cin >> pos >> s;
        als(0, 1, n + 1, pos, s);
        if (m[0].color[0] == "")
            cout << "blue\n";
        else
            cout << m[0].color[0] << "\n";
    }
}



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    solve();


}