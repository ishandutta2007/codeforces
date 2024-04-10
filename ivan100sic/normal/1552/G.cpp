// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct custom {
    ull p[2];
    
    custom() {
        p[0] = p[1] = 0;
    }

    char operator[] (int x) const {
        int idx = x >> 5;
        int pos = x & 31;
        return (p[idx] >> (2*pos)) & 3;
    }

    void set(int x, ull c) {
        int idx = x >> 5;
        int pos = x & 31;
        ull mask = 0;
        mask = ~mask;
        mask ^= 3ull << (2*pos);
        p[idx] &= mask;
        p[idx] |= c << (2*pos);
    }

    bool operator< (const custom& b) const {
        return tie(p[0], p[1]) < tie(b.p[0], b.p[1]);
    }

    bool operator== (const custom& b) const {
        return tie(p[0], p[1]) == tie(b.p[0], b.p[1]);
    }

    void operator&= (const custom& b) {
        p[0] &= b.p[0];
        p[1] &= b.p[1];
    }

    void operator|= (const custom& b) {
        p[0] |= b.p[0];
        p[1] |= b.p[1];
    }
};

void rej() {
    cout << "REJECTED\n";
    exit(0);
}

void acc() {
    cout << "ACCEPTED\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        if (n > 1) {
            rej();
        } else {
            acc();
        }
    }

    vector<custom> ol(1);
    for (int i=0; i<k; i++) {
        vector<int> p;
        int sz;
        cin >> sz;
        p.resize(sz);
        for (int& x : p) cin >> x, x--;

        custom keep;
        for (int i=0; i<n; i++) keep.set(i, 3);
        for (int i : p) keep.set(i, 0);

        vector<custom> masks(sz+1);
        for (int z=0; z<=sz; z++) {
            custom& t = masks[z];
            for (int i=0; i<z; i++) t.set(p[i], 1);
            for (int i=z; i<sz; i++) t.set(p[i], 2);
        }

        vector<custom> nu;
        for (const auto& s : ol) {
            int c0=0, c1=0, cu=0;
            for (int x : p) {
                switch (s[x]) {
                    case 1: c0++; break;
                    case 2: c1++; break;
                    default: cu++;
                }
            }

            for (int z=c0; z<=c0+cu; z++) {
                custom t = s;
                t &= keep;
                t |= masks[z];

                if (i == k - 1) {
                    int state = 0;
                    for (int i=0; i<n; i++) {
                        int c = t[i];
                        if (state == 0) {
                            if (c != 1) {
                                state = 1;
                            }
                        } else {
                            if (c != 2) {
                                rej();
                            }
                        }
                    }
                } else {
                    nu.push_back(t);
                }
            }
        }

        if (i == k - 1) {
            cout << "ACCEPTED\n";
        } else {
            sort(begin(nu), end(nu));
            nu.erase(unique(begin(nu), end(nu)), end(nu));
            swap(ol, nu);
        }
    }
}