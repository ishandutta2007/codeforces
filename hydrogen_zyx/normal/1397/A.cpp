#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt[300];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (auto x : s) cnt[x]++;
        }
        bool f = 1;
        for (int i = 'a'; i <= 'z'; i++)
            if (cnt[i] % n) f = 0;
        if (f)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}