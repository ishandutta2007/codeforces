#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long llong;
typedef pair<llong, llong> pll;

int n;
llong V[3], Q[100001][3];
pll P[100001];
int I[3];

llong gcd(llong x, llong y) {
    for (; y; swap(x, y)) x %= y;
    return max(x, 1ll);
}

pll get(int it) {
    llong x = 0, m = 0, R[3] = {};
    for (int i = 0; i < 3; ++i) {
        x += V[i] * V[i];
        m += V[i] * Q[it][i];
    }
    for (int i = 0; i < 3; ++i) {
        R[i] = x * Q[it][i] - m * V[i];
    }
    llong g = gcd(abs(R[1]), abs(R[2]));
    return pll(R[1] / g, R[2] / g);
}

int ccw(pll a, pll b) {
    if (a == b) return 0;
    long double ld = 1.L * a.x * b.y - 1.L * a.y * b.x;
    if (ld > 0) return 1;
    return -1;
}

struct cmp {
    bool operator()(const pll &a, const pll &b) const {
        if (a.y < 0 && b.y > 0) return 0;
        if (a.y > 0 && b.y < 0) return 1;
        if (a.y == 0 && b.y == 0) return a.x > b.x;
        if (a.x > 0 && a.y == 0) return 1;
        if (b.x > 0 && b.y == 0) return 0;
        return ccw(a, b) > 0;
    }
};

pll operator-(pll a) {
    return pll(-a.x, -a.y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 3; ++i) {
        cin >> V[i];
        I[i] = i;
    }
    for (int i = 0, j = 0; i < 3; ++i) {
        if (V[i] > 0) swap(V[i], V[j]), swap(I[i], I[j]), ++j;
    }
    int idx = 0;
    int cnt0 = 0, cnt180 = 0;
    llong cntP = 0;
    map<pll, int, cmp> mp;
    cin >> n;
    for (int it = 1; it <= n; ++it) {
        char T[5];
        cin >> T;
        if (T[0] == 'A') {
            ++idx;
            llong in[3];
            for (int i = 0; i < 3; ++i) cin >> in[i];
            for (int i = 0; i < 3; ++i) Q[idx][i] = in[I[i]];
            P[idx] = get(idx);
            if (P[idx] == pll(0, 0)) ++cnt0;
            else {
                if (++mp[P[idx]] == 1) {
                    auto it = mp.find(P[idx]);
                    if (it != mp.begin() && next(it) != mp.end()) {
                        if (ccw(prev(it)->x, next(it)->x) < 0) --cnt180;
                    }
                    if (it != mp.begin()) {
                        if (ccw(prev(it)->x, it->x) < 0) ++cnt180;
                    }
                    if (next(it) != mp.end()) {
                        if (ccw(it->x, next(it)->x) < 0) ++cnt180;
                    }
                }
                if (mp.count(-P[idx])) cntP += mp[-P[idx]];
            }
        }
        else {
            int idx;
            cin >> idx;
            if (P[idx] == pll(0, 0)) --cnt0;
            else {
                if (--mp[P[idx]] == 0) {
                    auto it = mp.find(P[idx]);
                    if (it != mp.begin() && next(it) != mp.end()) {
                        if (ccw(prev(it)->x, next(it)->x) < 0) ++cnt180;
                    }
                    if (it != mp.begin()) {
                        if (ccw(prev(it)->x, it->x) < 0) --cnt180;
                    }
                    if (next(it) != mp.end()) {
                        if (ccw(it->x, next(it)->x) < 0) --cnt180;
                    }
                    mp.erase(it);
                }
                if (mp.count(-P[idx])) cntP -= mp[-P[idx]];
            }
        }
        if (cnt0) printf("1\n");
        else if (cntP) printf("2\n");
        else if (int(mp.size()) <= 1 || cnt180) printf("0\n");
        else if (ccw(mp.rbegin()->x, mp.begin()->x) < 0) printf("0\n");
        else printf("3\n"); 
    }
    return 0;
}