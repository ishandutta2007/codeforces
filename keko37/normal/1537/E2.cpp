#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;
const int MOD = 1000000007;
const int B = 31337;

int n, k;
string s;
int h[MAXN], pot[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void precompute () {
    pot[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) h[i] = add(mul(h[i - 1], B), s[i]); else h[i] = s[i];
        pot[i + 1] = mul(pot[i], B);
    }
}

llint get_hash (int i, int j) {
    if (i == 0) return h[j];
    return sub(h[j], mul(h[i - 1], pot[j - i + 1]));
}

bool isti (int i, int j, int len) {
    return get_hash(i, i + len - 1) == get_hash(j, j + len - 1);
}

bool cmp (int i, int j) {
    if (s[i] != s[j]) return s[i] < s[j];
    int lo = 1, hi = min(n - i, n - j);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (isti(i, j, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if (lo == n - j) return 0;
    return s[i + lo] < s[j + lo];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    while (s.size() < k) s = s + s;
    while (s.size() > k) s.pop_back();
    n = s.size();
    precompute();
    int ind = n;
    for (int i = 1; i < n; i++) {
        if (cmp(0, i)) {
            ind = i;
            break;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << s[i % ind];
    }
    return 0;
}