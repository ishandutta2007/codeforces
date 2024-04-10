#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string a, b;
    cin >> a >> b;
    
    vector<int> pre(b.size() + 1, 0);
    int next = 0;
    for (int i = 0; i < b.size(); i++) {
        while (next < a.size() && a[next] != b[i]) {
            next++;
        }

        next++;
        pre[i+1] = next;
    }

    vector<int> rev(b.size() + 1, a.size());
    next = a.size() - 1;
    for (int i = b.size() - 1; i >= 0; i--) {
        while (next >= 0 && a[next] != b[i]) {
            next--;
        }

        rev[i] = next;
        next--;
    }

    int best = b.size();
    int start = 0;

    for (int i = 0; i < rev.size(); i++) {
        // Use the first i values
        int allowed_index_in_a = pre[i];
        if (allowed_index_in_a > a.size()) {
            // int delet = b.size() - i;
            // if (delet < best) {
            //     best = delet;
            //     start = i;
            // }
        } else {
            auto it = lower_bound(rev.begin(), rev.end(), allowed_index_in_a);
            int idx = it - rev.begin();
            int delet = idx - i;
            if (best > delet) {
                best = delet;
                start = i;
            }
        }
    }

    if (best == b.size()) {
        cout << '-' << endl;
    } else {
        if (best <= 0) cout << b << endl; 
        else cout << b.substr(0, start) << b.substr(start + best) << endl;
    }

    return 0;
}