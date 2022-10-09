// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        if (mp.size() == 1) {
            cout << s << '\n';
            continue;
        }

        char f = 0;
        for (auto [k, v] : mp) {
            if (v == 1) {
                f = k;
                break;
            }
        }

        if (f) {
            cout << f;
            mp[f]--;
            for (auto [k, v] : mp) {
                cout << string(v, k);
            }
            cout << '\n';
            continue;
        }

        vector<char> q;
        for (auto [k, v] : mp) {
            q.push_back(k);
        }

        char a = q[0];
        if (mp[a] <= (n+2) / 2) {
            // moze aa
            string sol;
            sol += a;
            sol += a;

            int ca = mp[a] - 2;
            mp.erase(a);
            for (int i=2; i<n; i++) {
                if (sol.back() != a && ca > 0) {
                    ca--;
                    sol += a;
                } else {
                    char x = mp.begin()->first;
                    sol += x;
                    if (--mp[x] == 0) mp.erase(x);
                }
            }

            cout << sol << '\n';
        } else {
            // mora ab
            char b = q[1];
            string sol;
            sol += a;
            sol += b;

            // ako su to jedina dva slova, mora bbbb...aaa
            if (q.size() == 2) {
                sol += string(mp[b]-1, b);
                sol += string(mp[a]-1, a);
            } else {
                // slobodno stavi sve aove
                sol += string(mp[a]-1, a);
                sol += q[2];
                if (--mp[q[2]] == 0) mp.erase(q[2]);
                if (--mp[b] == 0) mp.erase(b);
                mp.erase(a);

                for (auto [k, v] : mp) {
                    sol += string(v, k);
                }
            }

            cout << sol << '\n';
        }
    }
}