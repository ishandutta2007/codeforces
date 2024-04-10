#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        
        bool all_equal = all_of(b.begin(), b.end(), [](int x){ return x == 0; }) ||
                         all_of(b.begin(), b.end(), [](int x){ return x == 1; });
        if (all_equal) {
            if (is_sorted(a.begin(), a.end()))
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}