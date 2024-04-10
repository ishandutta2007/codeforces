#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                cnt++;
            } else {
                a.push_back(x);
            }
        }
        if ((int) a.size() >= 5) {
            cout << "NO\n";
        } else {
            for (int i = 0; i < min(cnt, 3); i++) {
                a.push_back(0);
            }
            sort(a.begin(), a.end());
            int ok = 1;
            for (int i = 0; i < (int) a.size(); i++) {
                for (int j = i + 1; j < (int) a.size(); j++) {
                    for (int k = j + 1; k < (int) a.size(); k++) {
                        if (!binary_search(a.begin(), a.end(), a[i] + a[j] + a[k])) {
                            ok = 0;
                        }
                    }
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}