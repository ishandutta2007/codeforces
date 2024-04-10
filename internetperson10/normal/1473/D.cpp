#include <bits/stdc++.h>

using namespace std;

vector<int> p1, p2, m1, m2, o1, o2;
vector<int> ops;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, q;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> q >> s;
        ops.resize(n);
        p1.resize(n);
        p2.resize(n);
        m1.resize(n);
        m2.resize(n);
        o1.resize(n);
        o2.resize(n);
        for(int i = 0; i < n; i++) {
            if(s.at(i) == '+') ops[i] = 1;
            else ops[i] = -1;
        }
        if(ops[0] == 1) {
            p1[0] = 1;
            m1[0] = 0;
            o1[0] = 1;
        }
        else {
            p1[0] = 0;
            m1[0] = -1;
            o1[0] = -1;
        }
        for(int i = 1; i < n; i++) {
            if(ops[i] == 1) {
                o1[i] = o1[i-1]+1;
                p1[i] = max(p1[i-1], o1[i]);
                m1[i] = m1[i-1];
            }
            else {
                o1[i] = o1[i-1]-1;
                m1[i] = min(m1[i-1], o1[i]);
                p1[i] = p1[i-1];
            }
        }
        if(ops[n-1] == -1) {
            p2[n-1] = 1;
            m2[n-1] = 0;
            o2[n-1] = 1;
        }
        else {
            p2[n-1] = 0;
            m2[n-1] = -1;
            o2[n-1] = -1;
        }
        for(int i = n-2; i >= 0; i--) {
            if(ops[i] == -1) {
                o2[i] = o2[i+1]+1;
                p2[i] = max(p2[i+1], o2[i]);
                m2[i] = m2[i+1];
            }
            else {
                o2[i] = o2[i+1]-1;
                m2[i] = min(m2[i+1], o2[i]);
                p2[i] = p2[i+1];
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << p2[i] << ' ' << m2[i] << ' ' << o2[i] << '\n';
        // }
        while(q--) {
            int l, r, pp, mp, op, pf, mf, of;
            cin >> l >> r;
            l -= 2;
            if(l == -1) pp = mp = op = 0;
            else {
                pp = p1[l];
                mp = m1[l];
                op = o1[l];
            }
            if(r == n) pf = mf = of = 0;
            else {
                pf = p2[r];
                mf = m2[r];
                of = o2[r];
            }
            cout <<  max(pp, op + max(0, pf-of)) - min(mp, op + min(0, mf-of)) + 1 << '\n';
        }
    }
}