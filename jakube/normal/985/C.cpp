#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n * k);
    for (int i = 0; i < n * k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ma = a[0] + l;
    int smaller = upper_bound(a.begin(), a.end(), ma) - a.begin();
    if (smaller < n) {
        cout << 0 << '\n';
        return 0;
    }
        
    stack<int> b, c;
    for (int i = 0; i < smaller; i++) {
        b.push(a[i]);
    }
    for (int i = smaller; i < n * k; i++) {
        c.push(a[i]);
    }
    
    long long volume = 0;
    for (int i = 0; i < n; i++) {
        int mi = b.top();
        b.pop();
        int K = k - 1;
        while (K && !c.empty()) {
            K--;
            c.pop();
        }
        while (K) {
            K--;
            mi = b.top();
            b.pop();
        }
        volume += mi;
    }
    cout << volume << '\n';
    
}