#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;
const int mod = 1000000007;
int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }

const int maxn = 1000500;

int n, k;
char s[maxn];
int d[maxn];
vector<int> q;

void addc(int c) {
    forn(i, k) if (i != c) d[c] = add(d[c], d[i]);
    d[c] = add(d[c], 1);
    q.erase(find(q.begin(), q.end(), c));
    q.push_back(c);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    scanf("%s", s);
    forn(i, k) q.push_back(i);
    for (char *r = s; *r; ++r) addc(*r-'a');
    forn(i, n) addc(q[0]);
    int res = 1;
    forn(i, k) res = add(res, d[i]);
    cout << res << endl;

    return 0;
}