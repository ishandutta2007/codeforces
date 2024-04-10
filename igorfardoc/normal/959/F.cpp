#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int mod = 1000000007;
int basis[20];
int d = 20;
int sz = 0;
int p[200000];

void add(int mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & 1 << i) == 0) continue;

        if (!basis[i]) {
            basis[i] = mask;
            ++sz;
            return;
        }

        mask ^= basis[i];
    }
}

bool check(int mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) return false;

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
    return true;
}


int main()
{
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    p[0] = 1;
    for(int i = 1; i < 200000; i++) {
        p[i] = p[i - 1] * 2 % mod;
    }
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int now = 0;
    vector<array<int, 3>> qu(q);
    vi ans(q, 0);
    for(int i = 0; i < q; i++) {
        int l, x;
        cin >> l >> x;
        --l;
        qu[i] = {l, x, i};
    }
    sort(qu.begin(), qu.end());
    for(int i = 0; i < q; i++) {
        while(now <= qu[i][0]) {
            add(a[now]);
            ++now;
        }
        int here = qu[i][1];
        if(check(here)) {
            ans[qu[i][2]] = p[now - sz];
        }
    }
    for(const auto& el : ans) {
        cout << el << '\n';
    }
}