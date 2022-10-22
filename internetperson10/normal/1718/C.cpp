#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    multiset<ll> s;
    vector<ll> d;
    vector<int> nums(n);
    vector<vector<ll>> sums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 1; i < n; i++) {
        if(n % i == 0) d.push_back(i);
    }
    for(int i = 1; i < d.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(min(d[i], d[j]) == -1) continue;
            if(d[i] % d[j] == 0) d[j] = -1;
        }
    }
    sort(d.rbegin(), d.rend());
    while(d.back() == -1) d.pop_back();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d.size(); j++) {
            if(i >= d[j]) break;
            sums[i].push_back(0);
            for(int k = i; k < n; k += d[j]) {
                sums[i][j] += nums[k];
            }
            sums[i][j] *= (d[j]);
            s.insert(sums[i][j]);
        }
    }
    cout << *(--s.end()) << '\n';
    while(q--) {
        int p, x;
        cin >> p >> x;
        p--;
        for(int j = 0; j < d.size(); j++) {
            int pos = p % d[j];
            auto it = s.find(sums[pos][j]);
            ll new_val = sums[pos][j] + (x - nums[p]) * (d[j]);
            s.insert(new_val);
            s.erase(it);
            sums[pos][j] = new_val;
        }
        nums[p] = x;
        cout << *(--s.end()) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}