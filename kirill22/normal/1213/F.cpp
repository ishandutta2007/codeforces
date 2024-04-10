#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0;
    char c = 'a';
    unordered_set<int> A, B;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    string s(n, 'a');
    for (int i = 0; i < n; i++) {
        if (B.find(a[i]) != B.end()) {
            s[a[i]] = c;
            B.erase(a[i]);
        }
        else {
            A.insert(a[i]);
        }
        if (A.find(b[i]) != A.end()) {
            s[b[i]] = c;
            A.erase(b[i]);
        }
        else {
            B.insert(b[i]);
        }
        if (A.size() == B.size() && A.size() == 0) {
            c = c + 1;
            c = min(c, 'z');
            ans++;
        }
    }
    if (ans >= k) {
        cout << "YES" << endl << s;
    }
    else {
        cout << "NO";
    }
}