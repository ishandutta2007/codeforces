#include <bits/stdc++.h>
using namespace std;

void norm(vector<int> &arr, array<int, 2> &p) {
    int mn = arr[0];
    for (int x : arr) {
        mn = min(x, mn);
    }
    mn = min(mn, min(p[0], p[1]));
    for (int &x : arr) {
        x -= mn;
    }
    p[0] -= mn; p[1] -= mn;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> d1(n), d2(n);
        for (int i = 0; i < n; ++i) {
            cin >> d1[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> d2[i];
        }
        sort(d2.begin(), d2.end());
        sort(d1.begin(), d1.end());
        if (d1 == d2) {
            cout << "YES" << '\n';
            for (int i : d1) {
                cout << i << " ";
            }
            cout << '\n';
            cout << 0 << " " << 0 << '\n';
            continue;
        }
        vector<int> cs;
        for (int i = 0; i < n; ++i) {
            cs.push_back(d1[n - 1] + d2[i]);
            cs.push_back(abs(d1[n - 1] - d2[i]));
        }
        bool f = false;
        for (int c : cs) {
            unordered_map<int, int> st1, st2;
            for (int d : d1) {
                st1[d]++;
            }
            for (int d : d2) {
                st2[d]++;
            }
            array<int, 2> p = {0, c};
            bool can = true;
            vector<int> h;
            int lst1 = n - 1, lst2 = n - 1;
            while (lst1 >= 0 && lst2 >= 0) {
                if (d1[lst1] > d2[lst2]) {
                    if (st1[d1[lst1]] == 0) {
                        lst1--;
                        continue;
                    }
                    int a = d1[lst1];
                    lst1--;
                    st1[a]--;
                    if (st2[abs(a - c)] == 0) {
                        can = false;
                        break;
                    }
                    st2[abs(a - c)]--;
                    h.push_back(a);
                } else {
                    if (st2[d2[lst2]] == 0) {
                        lst2--;
                        continue;
                    }
                    int a = d2[lst2];
                    lst2--;
                    st2[a]--;
                    if (st1[abs(a - c)] == 0) {
                        can = false;
                        break;
                    }
                    st1[abs(a - c)]--;
                    if (c > a) {
                        h.push_back(abs(a - c));
                    } else {
                        h.push_back(-abs(a - c));
                    }
                }
            }
            if (can) {
                f = true;
                norm(h, p);
                cout << "YES" << '\n';
                for (int x : h) {
                    cout << x << " ";
                }
                cout << '\n' << p[0] << " " << p[1] << '\n';
                break;
            }
        }
        if (!f) {
            cout << "NO" << '\n';
        }
    }
    return 0;
}