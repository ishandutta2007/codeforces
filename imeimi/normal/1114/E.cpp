#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long llong;

int query1(int x) {
    static map<int, int> mp;
    if (mp.find(x) != mp.end()) return mp[x];
    int v;
    cout << "? " << x << endl;
    cin >> v;
    if (v != -1) return mp[x] = v;
    exit(1);
}

int query2(int x) {
    static map<int, int> mp;
    if (mp.find(x) != mp.end()) return mp[x];
    int v;
    cout << "> " << x << endl;
    cin >> v;
    if (v != -1) return mp[x] = v;
    exit(1);
}

int gcd(int x, int y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int mx, cnt = 0;
    {
        int s = 0, e = 1e9;
        while (s < e) {
            int m = (s + e) / 2;
            if (query2(m)) s = m + 1;
            else e = m;
            ++cnt;
        }
        mx = s;
    }
    int ans = 0;
    srand(time(0));
    set<int> sp;
    for (; cnt < 60; ++cnt) {
        int x;
        do {
            x = (rand() * 100000ll + rand()) % n + 1;
        } while (sp.count(x));
        ans = gcd(ans, mx - query1(x));
    }
    cout << "! " << mx - (n - 1ll) * ans << ' ' << ans << endl;
    return 0;
}