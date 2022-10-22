#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<ll>> a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    a.resize(100001);
    b.resize(100001);
    vector<vector<ll>> nums(r);
    for(int i = 0; i < r; i++) {
        nums[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> nums[i][j];
            a[nums[i][j]].push_back(i);
            b[nums[i][j]].push_back(j);
        }
    }
    ll tot = 0;
    for(auto &v : a) {
        sort(v.begin(), v.end());
        ll sum = 0;
        for(ll i = 0; i < v.size(); i++) {
            tot += ((i) * v[i]) - sum;
            sum += v[i];
        }
    }
    for(auto &v : b) {
        sort(v.begin(), v.end());
        ll sum = 0;
        for(ll i = 0; i < v.size(); i++) {
            tot += ((i) * v[i]) - sum;
            sum += v[i];
        }
    }
    cout << tot << '\n';
}