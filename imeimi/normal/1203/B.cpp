#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n;
bool solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= (n << 2); ++i) {
        int x;
        cin >> x;
        ++mp[x];
    }
    vector<int> v;
    for (auto it : mp) {
        if (it.se & 1) return 0;
        for (int i = it.se >> 1; i--; ) v.push_back(it.fs);
    }
    int S = v[0] * v.back();
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] * v[v.size() - 1 - i] != S) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) printf(solve() ? "YES\n" : "NO\n");
    return 0;
}