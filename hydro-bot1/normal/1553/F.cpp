// Hydro submission #617b55db02b8aac5232fcae2@1635472860151
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
using LL = long long;

const int M = 3e5 + 5;

class BIT {
   private:
    LL tree[M];

   public:
    void add(int x, int y) {
        for (; x < M; x += x & (-x)) tree[x] += y;
    }

    LL sum(int x) {
        LL res = 0;
        for (; x; x &= x - 1) res += tree[x];
        return res;
    }
} t1, t2;

template <class T>
void read(T &ret) {
    ret = 0;
    char ch = getchar();
    bool found = false;
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') ch = getchar(), found = true;
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    if (found) ret = -ret;
}

template <class T, class... Args>
void read(T &ret, Args &...rest) {
    read(ret), read(rest...);
}

int main() {
    int n;
    read(n);
    LL ans = 0, sum = 0;
    for (int i = 1, a; i <= n; i++) {
        read(a);
        ans += static_cast<LL>(a) * (i - 1) - t1.sum(a);
        for (int j = a; j < M; j += a) t1.add(j, a);
        ans += sum, sum += a;
        for (int j = a, k = 1; j < M; j += a, k++)
            ans -= k * (t2.sum(min(j + a - 1, M - 1)) - t2.sum(j - 1)) * a;
        t2.add(a, 1);
        printf("%lld ", ans);
    }
    return puts(""), 0;
}