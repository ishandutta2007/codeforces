#include <bits/stdc++.h>
using namespace std;

struct S {
    int l, r, idx;
    int sol = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<S> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i].l >> s[i].r;
            s[i].idx = i;
        }
        sort(s.begin(), s.end(), [](S a, S b) {
            if (a.l == b.l)
                return a.idx < b.idx;
            return a.l < b.l; 
        });
        
        queue<pair<int, int>> q;
        int i = 0;
        for (int t = 1; t < 5000; t++) {
            while (i < n && s[i].l == t) {
                q.push({s[i].r, s[i].idx});
                i++;
            }
            while (!q.empty() && q.front().first < t) {
                q.pop();
            }
            if (!q.empty() && q.front().first >= t) {
                s[q.front().second].sol = t;
                q.pop();
            }
        }

        sort(s.begin(), s.end(), [](auto a, auto b) {
            return a.idx < b.idx;
        });
        for (int i = 0; i < n; i++) {
            cout << s[i].sol << ' ';
        }
        cout << '\n';
    }
}