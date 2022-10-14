#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, m;
llint a[MAXN], s[MAXN], t[MAXN];
llint b[4] = {200003, 200009, 200017, 200023};
llint mod[4] = {1000000007, 961748941, 961748947, 961748951};
llint hs[MAXN] [4], ht[MAXN] [4], pot[MAXN] [4];
vector <llint> v;

inline llint add (llint a, llint b, int ind) {
    a += b;
    if (a >= mod[ind]) a -= mod[ind];
    return a;
}

inline llint sub (llint a, llint b, int ind) {
    a -= b;
    if (a < 0) a += mod[ind];
    return a;
}

inline llint mul (llint a, llint b, int ind) {
    return a * b % mod[ind];
}

void precompute () {
    for (int j=0; j<4; j++) {
        pot[0] [j] = 1;
        hs[0] [j] = s[0];
        ht[0] [j] = t[0];
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<4; j++) {
            pot[i] [j] = mul(pot[i-1] [j], b[j], j);
            hs[i] [j] = add(mul(hs[i-1] [j], b[j], j), s[i], j);
            ht[i] [j] = add(mul(ht[i-1] [j], b[j], j), t[i], j);
        }
    }
}

llint geth_s (int a, int b, int ind) {
    if (a == 0) return hs[b] [ind];
    return sub(hs[b] [ind], mul(hs[a-1] [ind], pot[b-a+1] [ind], ind), ind);
}

llint geth_t (int a, int b, int ind) {
    if (a == 0) return ht[b] [ind];
    return sub(ht[b] [ind], mul(ht[a-1] [ind], pot[b-a+1] [ind], ind), ind);
}

bool isti (int a1, int b1, int a2, int b2) {
    for (int i=0; i<4; i++) {
        if (geth_s(a1, b1, i) != geth_t(a2, b2, i)) return 0;
    }
    return 1;
}

bool probaj (int len) {
    if (len == 0) return isti(0, n-1, 0, n-1);
    return isti(0, len - 1, n - len, n - 1) && isti(len, n-1, 0, n - len - 1);
}

int main () {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        scanf("%I64d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        if (i < n-1) {
            s[i] = a[i+1] - a[i];
        } else {
            s[i] = m-1 - a[i] + a[0] + 1;
        }
        t[n-1 - i] = s[i];
    }
    precompute();
    for (int i=0; i<n; i++) {
        if (probaj(i)) v.push_back((a[i] + a[0]) % m);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i=0; i<v.size(); i++) {
        printf("%I64d ", v[i]);
    }
    return 0;
}