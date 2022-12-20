#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int len = 150;

struct def {
    int l, r, x, pr;
};

def m[20 * N];
int top = 0;

int merg(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (m[a].pr > m[b].pr) {
        m[a].r = merg(m[a].r, b);
        return a;
    } else {
        m[b].l = merg(a, m[b].l);
        return b;
    }
}

void split(int root, int &a, int &b, int x) {
    if (root == 0) {
        a = 0;
        b = 0;
        return;
    }
    if (m[root].x <= x) {
        split(m[root].r, m[root].r, b, x);
        a = root;
    } else {
        split(m[root].l, a, m[root].l, x);
        b = root;
    }
}

int newx(int x) {
    ++top;
    m[top].pr = rand();
    m[top].x = x;
    return top;
}

int inser(int root, int top) {
    int a, b;
    split(root, a, b, m[top].x);
    return merg(a, merg(top, b));
}

int find_min(int root, int x) {
    if (m[root].x == x)
        return x;
    if (m[root].x > x)
        if (m[root].l != 0)
            return min(m[root].x, find_min(m[root].l, x));
        else
            return m[root].x;
    else if (m[root].r != 0)
            return min((int)1e9, find_min(m[root].r, x));
        else
            return 1e9;
}

bool b[N];
int t[20], rt[N];

int main() {
    int i, j, n, x, k, s, tt, u;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    t[0] = 1;
    for (i = 1; i < 17; ++i)
        t[i] = t[i - 1] * 2;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> tt;
        if (tt == 1) {
            cin >> u;
            if (b[u])
                continue;
            b[u] = true;
            for (j = 1; j <= len; ++j)
            if (u % j == 0)
                rt[j] = inser(rt[j], newx(u));
        } else {
            cin >> x >> k >> s;
            if (x % k != 0) {
                cout << -1 << "\n";
                continue;
            }
            if (k > len) {
                long long ans = -1, ans1 = -1;
                for (j = 1; j * k <= N; ++j)
                if (b[j * k] && x + j * k <= s)
                if (ans < ((j * k) ^ x)) {
                    ans = (j * k) ^ x;
                    ans1 = j * k;
                }
                cout << ans1 << "\n";
                continue;
            }
            int a, b;
            split(rt[k], a, b, s - x);
            if (a == 0) {
                cout << -1 << "\n";
                continue;
            }
            int ans = 0, tek = 0;
            for (j = 16; j >= 0; --j) {
                if ((x & t[j]) == 0)
                    if (find_min(a, tek + t[j]) < tek + 2 * t[j]) {
                        tek += t[j];
                        ans += t[j];
                    } else
                        tek = tek;
                else {
                    if (find_min(a, tek) < tek + t[j])
                        ans += t[j];
                    else
                        tek += t[j];
                }
            }
            rt[k] = merg(a, b);
            cout << tek << "\n";
        }
    }
}