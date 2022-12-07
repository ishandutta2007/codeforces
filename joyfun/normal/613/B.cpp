#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100005;
const long long INF = 100000000000000000LL;

int n;
ll A, cf, cm, m;
struct SB {
    ll a;
    int id;
    void read(int id) {
        scanf("%lld", &a);
        this->id = id;
    }
    bool operator < (const SB& c) const {
        return a < c.a;
    }
} s[N];

bool cmpid(SB a, SB b) {
    return a.id < b.id;
}

ll sum[N];

int find(int l, int r, ll x) {
    while (l < r) {
        int mid = (l + r)>>1;
        if (s[mid].a >= x) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

ll cal(int n, ll yu) {
    ll l = 0, r = A + 1;
    while (l < r) {
        ll mid = (l + r)>>1;
        int v = find(1, n + 1, mid);
       // printf("%d %d %lld\n", n, v, mid);
        if (mid * v - sum[v] > yu) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    scanf("%d%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
    for (int i = 1; i <= n; i++) s[i].read(i);
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i].a;
    ll Max = -INF;
    int Maxv;
    for (int i = 0; i <= n; i++) {
        ll need = A * i - (sum[n] - sum[n - i]);
        if (need > m) continue;
        ll yu = m - need;
        ll tmp = cal(n - i, yu) * cm + cf * i;
        if (Max < tmp) {
            Max = tmp;
            Maxv = i;
        }
    }
   // printf("%d\n", Maxv);
    printf("%lld\n", Max);
    ll need = A * Maxv - (sum[n] - sum[n - Maxv]);
    ll yu = m - need;
   // printf("%lld\n", yu);
    ll Min = cal(n - Maxv, yu);
    for (int i = 1; i <= n - Maxv; i++) {
        if (s[i].a < Min) s[i].a = Min;
    }
    for (int i = n - Maxv + 1; i <= n; i++)
        s[i].a = A;
    sort(s + 1, s + 1 + n, cmpid);
    for (int i = 1; i <= n; i++)
        printf("%lld ", s[i].a);
    printf("\n");
    return 0;
}