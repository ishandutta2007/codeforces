#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 22;

struct node {
    int cnt = 0, d = 0;
    long long sum = 0, sum2 = 0;
    node() {}
};

node t[4 * N];
int n, d;

void push(int v, int l, int r) {
    if (l + 1 != r) {
        t[v * 2 + 1].d += t[v].d;
        t[v * 2 + 2].d += t[v].d;
    }
    t[v].sum2 += t[v].d * 1ll * t[v].d * t[v].cnt + 2 * 1ll * t[v].d * t[v].sum;
    t[v].sum += t[v].cnt * t[v].d;
    t[v].d = 0;
}

long long get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) {
        return 0ll;
    }
    if (l1 <= l && r <= r1) {
        long long A = t[v].sum2, B = t[v].sum;
        return (A - B) / 2;
    }
    int m = (l + r) / 2;
    return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m, r, l1, r1);
}

int get2(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) {
        return 0;
    }
    if (l1 <= l && r <= r1) {
        return t[v].cnt;
    }
    int m = (l + r) / 2;
    return get2(v * 2 + 1, l, m, l1, r1) + get2(v * 2 + 2, m, r, l1, r1);
}

void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) {
        return;
    }
    if (l1 <= l && r <= r1) {
        t[v].d += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v].sum = t[v * 2 + 1].sum + t[v * 2 + 2].sum;
    t[v].cnt = t[v * 2 + 1].cnt + t[v * 2 + 2].cnt;
    t[v].sum2 = t[v * 2 + 1].sum2 + t[v * 2 + 2].sum2;
}

void Set(int v, int l, int r, int i, int x) {
    push(v, l, r);
    if (i < l || i >= r) {
        return;
    }
    if (l + 1 == r) {
        if (x == -1) {
            t[v].sum = t[v].sum2 = t[v].cnt = 0;
        } else {
            t[v].sum = x;
            t[v].sum2 = x * 1ll * x;
            t[v].cnt = 1;
        }
        return;
    }
    int m = (l + r) / 2;
    Set(v * 2 + 1, l, m, i, x);
    Set(v * 2 + 2, m, r, i, x);
    t[v].sum = t[v * 2 + 1].sum + t[v * 2 + 2].sum;
    t[v].cnt = t[v * 2 + 1].cnt + t[v * 2 + 2].cnt;
    t[v].sum2 = t[v * 2 + 1].sum2 + t[v * 2 + 2].sum2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    set<int> was;
    while (n--) {
        int x;
        cin >> x;
        if (was.find(x) != was.end()) {
            update(0, 0, N, max(0, x - d), x, -1);
            Set(0, 0, N, x, -1);
            was.erase(x);
        } else {
            int res = get2(0, 0, N, x, min(N, x + d + 1));
            update(0, 0, N, max(0, x - d), x, 1);
            Set(0, 0, N, x, res);
            was.insert(x);
        }
        cout << get(0, 0, N, 0, N) << '\n';
    }
}