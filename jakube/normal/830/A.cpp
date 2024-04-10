#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, p;
    cin >> n >> k >> p;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> left_keys, right_keys;
    // for (int i = 0; i < b.size(); i++) {
    //     if (b[i] <= p)
    //         left_keys.push_back(b[i]);
    //     else
    //         right_keys.push_back(b[i]);
    // }

    int best = numeric_limits<int>::max();

    for (int i = 0; i + n <= k; i++) {
        int ma = 0;
        for (int per = 0; per < n; per++) {
            int pp = a[per];
            int pk = b[i+per];
            if (pp <= pk && pk <= p)
                ma = max(ma, p - pp);
            else if (pk <= pp && pp <= p)
                ma = max(ma, p - pk + pp - pk);
            else if (p <= pk && pk <= pp)
                ma = max(ma, pp - p);
            else if (pp <= p && p <= pk)
                ma = max(ma, pk - pp + pk - p);
            else if (p <= pp && pp <= pk)
                ma = max(ma, pk-pp + pk - p);
            else if (pk <= p && p <= pp)
                ma = max(ma, pp - pk + p - pk);
        }
        best = min(best, ma);
    }


    cout << best << endl;
}