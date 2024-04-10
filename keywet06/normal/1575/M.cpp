#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

using int64 = long long;
using vi = vector<int>;
using pi = pair<int, int>;

const int mod = 1000000007;
const int N = 2005;

template <typename T>
bool mid(T &a, T b) {
    return (b < a) ? a = b, 1 : 0;
}

char s[N][N];

int st[N];
int nr[N][N];

int64 ans;

int sqr(int a) { return a * a; }

vi calc(vi a) {
    auto chk = [&](int i, int j) { return a[i] + 1ll * (j - i) * (j - i); };

    auto ins = [&](int i, int j, int k) {
        int64 cur = 1ll * (j - i) * (a[k] + sqr(k) - a[j] - sqr(j)) -
                 1ll * (k - j) * (a[j] + sqr(j) - a[i] - sqr(i));
        return cur;
    };
    int fr = 0, ed = 0;
    vi res(a.size());
    for (int i = 0; i < a.size(); i++) {
        while (ed - fr >= 2 && ins(st[ed - 2], st[ed - 1], i) <= 0) ed--;
        st[ed++] = i;
        while (ed - fr >= 2 && chk(st[fr + 1], i) <= chk(st[fr], i)) fr++;
        res[i] = chk(st[fr], i);
    }
    return res;
}

void upd(vi a) {
    vi t = calc(a);
    reverse(a.begin(), a.end());
    vi s = calc(a);
    reverse(s.begin(), s.end());
    for (int i = 0; i < t.size(); i++) {
        mid(t[i], s[i]);
        ans += t[i];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j <= m; j++) {
            if (s[i][j] == '0')
                nr[i][j] = N * 2;
            else
                nr[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) mid(nr[i][j], nr[i][j - 1] + 1);
        for (int j = m - 1; j >= 0; j--) mid(nr[i][j], nr[i][j + 1] + 1);
    }
    for (int j = 0; j <= m; j++) {
        vi cur(n + 1);
        for (int i = 0; i <= n; i++) cur[i] = 1ll * nr[i][j] * nr[i][j];
        upd(cur);
    }
    cout << ans << endl;
    return 0;
}