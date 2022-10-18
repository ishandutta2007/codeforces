#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    vector<int> prev(n, 0);
    vector<int> cnt(n, 0);
    // int p = 0;
    bool b = true;
    prev[0] = -1;
    for (int i = 1; i < n; i++) {
        if (b) {
            if (v[i] < v[i-1])
                b = !b;
        }

        if (!b) {
            int start = i-1;
            int m = 0;
            while (start >= 0 && v[start] < v[i]) {
                m = max(cnt[start], m);
                start = prev[start];
            }
            if (start == -1) {
                cnt[i] = 0;
                prev[i] = -1;
            }
            else {
                cnt[i] = m + 1;
                prev[i] = start;
            }
        }
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;
    
    
    // int c = 0;
    // vector<int> v2(v);
    // do {
    //     v = v2;
    //     for(int z : v) cout << z << " ";cout << endl;
    //     v2.clear();
    //     v2.push_back(v[0]);
    //     for (int i = 1; i < v.size(); i++) {
    //         if (v[i-1] < v[i])
    //             v2.push_back(v[i]);
    //     }
    //     c++;
    // }
    // while (v.size() != v2.size());

    // cout << c-1 << endl;

    return 0;
}