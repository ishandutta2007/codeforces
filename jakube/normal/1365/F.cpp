#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> make_min(vector<int> v) {
    // int n = v.size();
    // int many = n / 2;
    // for (int i = 0; i < n / 2; i++) {
    //     // find min
    //     int min_pos = 0;
    //     for (int j = 0; j < many; j++) {
    //         if (pair(v[j], v[n-1-j]) < pair(v[min_pos], v[n-1-min_pos]))
    //             min_pos = j;
    //         if (v[n-1-j] < v[min_pos])
    //             min_pos = n-1-j;
    //     }
        
    //     if (min_pos < many) {
    //         swap_ranges(v.begin(), v.begin() + min_pos + 1, v.end() - min_pos - 1);
    //         swap_ranges(v.begin(), v.begin() + many, v.end() - many);
    //     } else {
    //         int tmp = n - min_pos;
    //         swap_ranges(v.begin(), v.begin() + tmp, v.end() - tmp);
    //         swap_ranges(v.begin(), v.begin() + 1, v.end() - 1);
    //         swap_ranges(v.begin(), v.begin() + many, v.end() - many);
    //     }

    //     many--;
    // }

    int n = v.size();
    vector<pair<int, int>> p;
    for (int i = 0; i < (n + 1) / 2; i++) {
        int x = v[i];
        int y = v[n-1-i];
        p.emplace_back(min(x,y), max(x,y));
    }
    sort(p.begin(), p.end());
    return p;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;
    
    if (make_min(a) == make_min(b))
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}