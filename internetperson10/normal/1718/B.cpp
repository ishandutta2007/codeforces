#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll fib[80];
int ct[81];

void solve() {
    int k;
    cin >> k;
    for(int i = 0; i < 80; i++) ct[i] = 0;
    ll sum = 0;
    set<pair<int, int>> s;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        s.insert({x, i});
        sum += x;
        for(int j = 79; j >= 0; j--) {
            if(fib[j] <= x) {
                ct[j]++;
                x -= fib[j];
            }
        }
    }
    int base = -1;
    ll curr_sum = 0;
    for(int i = 0; i < 80; i++) {
        curr_sum += fib[i];
        if(curr_sum == sum) base = i;
    }
    if(base == -1) {
        cout << "NO\n";
        return;
    }
    if(base == 0) {
        cout << "YES\n";
        return;
    }
    if(base == 1) {
        if(k == 2) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    if(k == 1) {
        cout << "NO\n";
        return;
    }
    int prev = -1;
    for(int i = base; i >= 0; i--) {
        auto it = s.end();
        it--;
        if((*it).second == prev) it--;
        prev = (*it).second;
        auto p = make_pair((*it).first - fib[i], prev);
        s.erase(it);
        s.insert(p);
    }
    bool ok = true;
    for(auto p : s) {
        if(p.first < 0) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 80; i++) fib[i] = fib[i-1] + fib[i-2];
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}