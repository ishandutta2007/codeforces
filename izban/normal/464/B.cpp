#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct pt {
    int x[3];
    
    bool read() {
        if (!(cin >> x[0] >> x[1] >> x[2])) return 0;
        return 1;
    }
    
    pt() {}
    pt(int X, int Y, int Z) {
        x[0] = X;
        x[1] = Y;
        x[2] = Z;
    }
    
    ll operator^ (const pt &v) {
        ll res = 0;
        for (int i = 0; i < 3; i++) {
            res += 1LL * x[i] * v.x[i];
        }
        return res;
    }    
    
    ll len() {
        return (*this) ^ (*this);
    }
    
    pt operator- (const pt &p) {
        return pt(x[0] - p.x[0], x[1] - p.x[1], x[2] - p.x[2]);
    }
    
    pt operator+ (const pt &p) {
        return pt(x[0] + p.x[0], x[1] + p.x[1], x[2] + p.x[2]);
    }    
    
    void print() {
        for (int i = 0; i < 3; i++) cout << x[i] << " \n"[i + 1 == 3];
    }
    
    bool operator< (const pt &p) const {
        for (int i = 0; i < 3; i++) if (x[i] != p.x[i]) return x[i] < p.x[i];
        return 0;
    }
    
    bool operator== (const pt &p) const {
        bool ok = 1;
        for (int i = 0; i < 3; i++) ok &= x[i] == p.x[i];
        return ok;
    }
};

pt a[8];
int k[4];
bool was[8];

bool isok(vector<pt> &A, vector<pair<pt, int> > &b) {
    vector<pt> AA = A;
    for (int i = 0; i < 4; i++) {
        sort(A[i].x, A[i].x + 3);
        sort(b[i].first.x, b[i].first.x + 3);
    }
    sort(b.begin(), b.end());
    do {
        bool ok = 1;
        for (int i = 0; i < 4; i++) {
            ok &= A[i] == b[i].first;
        }
        if (ok) {
            cout << "YES" << endl;
            for (int i = 0; i < 4; i++) a[b[i].second] = AA[i];
            for (int i = 0; i < 8; i++) {
                a[i].print();
            }
            return 1;
        }
    } while (next_permutation(b.begin(), b.end()));
    return 0;
}

vector<pt> v1;
vector<pair<pt, int> > v2;

bool rec(int cur, int nxt) {
    if (nxt + (4 - cur) > 8) return 0;
    
    if (cur == 4) {
        pt v[3];
        for (int i = 1; i <= 3; i++) v[i - 1] = a[k[i]] - a[k[0]];
        bool ok = 1;
        for (int k1 = 0; k1 < 2; k1++) {
            for (int k2 = k1 + 1; k2 < 3; k2++) {
                ok &= v[k1].len() == v[k2].len();
                ok &= v[k1].len() != 0;
                ok &= (v[k1] ^ v[k2]) == 0;
            }
        }
        if (!ok) return 0;
        memset(was, 0, sizeof(was));
        for (int i = 0; i < 4; i++) was[k[i]] = 1;
        
        v1.clear();
        v2.clear();
        
        v1.push_back(a[k[0]] + v[0] + v[1]);
        v1.push_back(a[k[0]] + v[0] + v[2]);
        v1.push_back(a[k[0]] + v[1] + v[2]);
        v1.push_back(a[k[0]] + v[0] + v[1] + v[2]);
        for (int i = 0; i < 8; i++) if (!was[i]) {
            v2.push_back(make_pair(a[i], i));
        }
        
        if (isok(v1, v2)) {
            return 1;
        }
        
        return 0;
    }
    if (rec(cur, nxt + 1)) return 1;
    if (nxt == k[0]) return 0;
    k[cur] = nxt;
    sort(a[nxt].x, a[nxt].x + 3);
    do {
        if (rec(cur + 1, nxt + 1)) return 1;
    } while (next_permutation(a[nxt].x, a[nxt].x + 3));
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (a[0].read()) {
        for (int i = 1; i < 8; i++) {
            a[i].read();
            sort(a[i].x, a[i].x + 3);
        }
        
        bool ok = false;
        for (k[0] = 0; k[0] < 8 && !ok; k[0]++) {
            //cerr << k[0] << endl;
            do {
                ok |= rec(1, 0);
            } while (next_permutation(a[k[0]].x, a[k[0]].x + 3) && !ok);
        }
        if (!ok) {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}