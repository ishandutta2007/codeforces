#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        vector<int> cnt(n);
        int mx = -1;
        int mi = -1;
        for (int j = i; j < n; ++j) {
            ++cnt[ a[j] ];
            if (cnt[ a[j] ] > mx || cnt[ a[j] ] == mx && a[j] < mi) {
                mx = cnt[ a[j] ];
                mi = a[j];
            }
            ++ans[mi];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}