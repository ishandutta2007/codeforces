#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> used(n, 0);
        vector<int> z;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                int t = 1;
                tmp++;
                int j = i;
                used[j] = tmp;
                while (a[j] != i) {
                    t++;
                    j = a[j];
                    used[j] = tmp;
                }
                z.push_back(t);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << z[used[i] - 1] << " ";
        }
        cout << endl;
    }
}