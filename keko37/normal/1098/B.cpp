#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

int n, m;
string s[MAXN], t[MAXN];

int calc_r (int r, string dva) {
    int cnt = 0;
    for (int i=0; i<m; i++) {
        if (s[r] [i] == dva[i%2]) cnt++;
    }
    return cnt;
}

int calc_s (int r, string dva) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] [r] == dva[i%2]) cnt++;
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        t[i] = s[i];
    }
    string cet = "ACGT";
    int sol = 0, tip = 0;
    string soljen, soldva;
    do {
        string jen = "", dva = "", rjen, rdva;
        jen += cet[0]; jen += cet[1];
        dva += cet[2]; dva += cet[3];
        rjen = jen; reverse(jen.begin(), jen.end());
        rdva = dva; reverse(dva.begin(), dva.end());
        int res = 0;
        for (int i=0; i<n; i++) {
            if (i & 1) {
                res += max(calc_r(i, jen), calc_r(i, rjen));
            } else {
                res += max(calc_r(i, dva), calc_r(i, rdva));
            }
        }
        if (res > sol) {
            tip = 0;
            sol = res;
            soljen = jen;
            soldva = dva;
        }
        res = 0;
        for (int i=0; i<m; i++) {
            if (i & 1) {
                res += max(calc_s(i, jen), calc_s(i, rjen));
            } else {
                res += max(calc_s(i, dva), calc_s(i, rdva));
            }
        }
        if (res > sol) {
            tip = 1;
            sol = res;
            soljen = jen;
            soldva = dva;
        }
    } while (next_permutation(cet.begin(), cet.end()));
    if (tip == 0) {
        string jen = soljen, dva = soldva, rjen, rdva;
        rjen = jen; reverse(jen.begin(), jen.end());
        rdva = dva; reverse(dva.begin(), dva.end());
        for (int i=0; i<n; i++) {
            if (i & 1) {
                if (calc_r(i, jen) >= calc_r(i, rjen)) {
                    for (int j=0; j<m; j++) {
                        cout << jen[j%2];
                    }
                } else {
                    for (int j=0; j<m; j++) {
                        cout << rjen[j%2];
                    }
                }
            } else {
                if (calc_r(i, dva) >= calc_r(i, rdva)) {
                    for (int j=0; j<m; j++) {
                        cout << dva[j%2];
                    }
                } else {
                    for (int j=0; j<m; j++) {
                        cout << rdva[j%2];
                    }
                }
            }
            cout << endl;
        }
    } else {
        string jen = soljen, dva = soldva, rjen, rdva;
        rjen = jen; reverse(jen.begin(), jen.end());
        rdva = dva; reverse(dva.begin(), dva.end());
        for (int i=0; i<m; i++) {
            if (i & 1) {
                if (calc_s(i, jen) >= calc_s(i, rjen)) {
                    for (int j=0; j<n; j++) {
                        t[j] [i] = jen[j%2];
                    }
                } else {
                    for (int j=0; j<n; j++) {
                        t[j] [i] = rjen[j%2];
                    }
                }
            } else {
                if (calc_s(i, dva) >= calc_s(i, rdva)) {
                    for (int j=0; j<n; j++) {
                        t[j] [i] = dva[j%2];
                    }
                } else {
                    for (int j=0; j<n; j++) {
                        t[j] [i] = rdva[j%2];
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << t[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}