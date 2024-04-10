#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int ti = 0;
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            if(ti <= a[i]) {
                ti = a[i];
            }
            cout << b[i] - ti << ' ';
            ti = b[i];
        }
        cout << '\n';
    }
}