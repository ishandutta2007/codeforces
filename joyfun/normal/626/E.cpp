#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n;
long long x[N], sum[N];

long long cal(int v, int len) {
    return sum[v] - sum[v - 1 - len] + sum[n] - sum[n - len];
}

struct Ans {
    int v, len;
    Ans() {}
    Ans(int v, int len) {
        this->v = v;
        this->len = len;
    }
    long long get(long long c) const {
        return cal(v, len) * c - x[v] * (len * 2 + 1) * c;
    }
    bool operator < (const Ans& c) const {
        return get(c.len * 2 + 1) < c.get(len * 2 + 1);
    }
    void out() {
        printf("%d\n", len * 2 + 1);
        for (int i = v - len; i <= v; i++) printf("%lld ", x[i]);
        for (int i = n - len + 1; i <= n; i++) printf("%lld ", x[i]);
        printf("\n");
    }
};

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + x[i];
    Ans ans;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = min(n - i, i - 1);
        while (l < r) {
            int midl = (l * 2 + r) / 3;
            int midr = (l + r * 2 + 2) / 3;
            if (cal(i, midl) * (midr * 2 + 1) >= cal(i, midr) * (midl * 2 + 1)) r = midr - 1;
            else l = midl + 1;
        }
        if (i == 1) ans = Ans(i, l);
        else if (ans < Ans(i, l)) ans = Ans(i, l);
    }
    ans.out();
    return 0;
}