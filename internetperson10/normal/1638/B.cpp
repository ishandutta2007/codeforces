#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a, as, b, bs;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x%2) a.push_back(x);
            else b.push_back(x);
        }
        as = a; bs = b;
        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end());
        if(a == as && b == bs) cout << "Yes\n";
        else cout << "No\n";
    }
}