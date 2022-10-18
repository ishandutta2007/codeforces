#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i] -= n;
    }

    set<int> nums(a.begin(), a.end());
    a = vector<int>(nums.begin(), nums.end());

    if ( *max_element(a.begin(), a.end()) < 0 || *min_element(a.begin(), a.end()) > 0)
    {
        cout << -1 << endl;
        return 0;
    }

    bitset<2001> bs;
    bs[1000] = 1;

    for (int turn = 1; turn <= 1000; turn++) {
        bitset<2001> x;
        for (int v : a)
            if (v >= 0)
                x |= bs << v;
            else
                x |= bs >> -v;

        if (x[1000]) {
            cout << turn << endl;
            return 0;
        }
        bs = x;
    }

    cout << -1 << endl;
    return 0;
}