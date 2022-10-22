#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int a1 = 0, b1 = 0, c1 = 0;
        vector<char> d;
        for (int i = 0; i < n; i++) {
            char ci;
            cin >> ci;
            if (ci == 'R') {
                a1++;
            }
            if (ci == 'P') {
                b1++;
            }
            if (ci == 'S') {
                c1++;
            }
            d.push_back(ci);
        }
        int ans = min(a1, b) + min(b1, c) + min(c1, a);
        if (ans >= (n + 1) / 2) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                char ci;
                ci = d[i];
                if (ci == 'R') {
                    if (b > 0) {
                        b--;
                        a1--;
                        cout << "P";
                    }
                    else {
                        if (c > b1) {
                            c--;
                            cout << "S";
                        }
                        else {
                            a--;
                            cout << "R";
                        }
                    }
                }
                if (ci == 'P') {
                    if (c > 0) {
                        c--;
                        b1--;
                        cout << "S";
                    }
                    else {
                        if (a > c1) {
                            a--;
                            cout << "R";
                        }
                        else {
                            b--;
                            cout << "P";
                        }
                    }
                }
                if (ci == 'S') {
                    if (a > 0) {
                        a--;
                        c1--;
                        cout << "R";
                    }
                    else {
                        if (c > b1) {
                            c--;
                            cout << "S";
                        }
                        else {
                            b--;
                            cout << "P";
                        }
                    }
                }
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}