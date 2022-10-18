#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // vector<int> x;
    // for (int d = 1; d < 50; d++) {
    //     int sum = 0;
    //     cout << d << ": ";
    //     for (int i = 0; i < n; i++) {
    //         int c = (a[i] + d - 1) / d;
    //         cout << c * d - a[i] << " ";
    //         sum += c * d - a[i];
    //     }
    //     cout << "= " << sum << endl;
    //     x.push_back(sum);
    // }
    // cout << is_sorted(x.begin(), x.end()) << endl;
    
    set<int> pos_to_check;
    for (auto num : a) {
        for (int i = 1; i < 1000; i++)
        {
            pos_to_check.insert((num + i - 1) / i);
        }
    }
    vector<int> v(pos_to_check.begin(), pos_to_check.end());
    reverse(v.begin(), v.end());
    vector<int> ds(a.size());
    vector<int> mods(a.size());
    for (int val : v) {
        long long sum = 0;
        long long sumd = 0;
        for (int i = 0; i < n; i++) {
            ds[i] = (a[i] + val - 1) / val;
            sumd += ds[i];
            mods[i] = ds[i] * val - a[i];
            sum += mods[i];
        }
        if (sum <= k) {
            // cout << val << ": " << sum << " (" << sumd << ")" <<  endl;
            k -= sum;
            cout << val + k / sumd << endl;
            return 0;
        }
    }

    for (int val = v.back() - 1; val > 0; val--) {
        long long sum = 0;
        for (auto num : a) {
            int c = (num + val - 1) / val;
            sum += c * val - num;
        }
        if (sum <= k) {
            cout << val << endl;
            return 0;
        }
    }
}