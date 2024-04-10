#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pairs;

map<pairs, pairs> mp;

pairs go(long long v, int mx) {
    if (v == 0) return make_pair(0, 0);
    if (v < 10) {
        pairs ans = make_pair(1, 0);
        if (v < mx) ans.second = (mx - v);
        return ans;
    }
    pairs state = make_pair(v, mx);
    if (mp.find(state) != mp.end()) return mp[state];
    long long step = 1;
    while (step <= v / 10) step *= 10;
    pairs ans = make_pair(0, 0);
    while (true) {
        int dig = v / step;
        int newmx = mx;
        if (dig > newmx) newmx = dig;
        pairs cur = go(v % step, newmx);
        ans.first += cur.first;
        v -= v % step;
        if (cur.second > 0)
            v -= cur.second;
        else {
            v -= newmx;
            if (newmx > 0) ans.first++;
        }
        if (dig == 0) break;
    }
    ans.second = -v;
    mp[state] = ans;
    return ans;
}

int main() {
    long long n;
    cin >> n;
    mp.clear();
    pairs result = go(n, 0);
    cout << result.first << endl;
    return 0;
}