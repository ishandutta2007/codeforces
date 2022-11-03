#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);

    int n, k, x;
    map<int, int> mp;
    cin >> n >> k;
    vector<int> v;
    int mx = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if (mx + (n - i) == k) {
            for (int j = mx + 1; j <= k; ++j){
                v.push_back(j);
            }
            break;
        }
        ++mp[x];
        v.push_back(mp[x]);
        mx = max(mx, mp[x]);
        if(mp[x] > k) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}