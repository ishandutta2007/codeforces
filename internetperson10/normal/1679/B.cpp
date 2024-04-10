#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<ll, int>> nums(n);
    ll upd = -1, ti = -3;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i].first;
        sum += nums[i].first;
        nums[i].second = -2;
    }
    for(int t = 0; t < q; t++) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            sum += x;
            if(nums[i].second > ti) sum -= nums[i].first;
            else sum -= upd;
            nums[i] = {x, t};
        }
        else {
            cin >> upd;
            sum = upd * n;
            ti = t;
        }
        cout << sum << '\n';
    }
}