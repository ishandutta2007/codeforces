#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

constexpr int mod = 1000000007;

int muls[200001];
int divs[100001];

int pow(int a, int x) {
    if(x == 0) return 1;
    int b = pow(a, x / 2);
    b = (long long) b * b % mod;
    if(x % 2) b = (long long) b * a % mod;
    return b;
}

void preprocess() {
    muls[0] = 1;
    for(int i = 1; i <= 200000; i++)
        muls[i] = (long long) muls[i - 1] * i % mod;
    for(int i = 0; i <= 100000; i++)
        divs[i] = pow(muls[i], mod - 2);
}

int comb(int w, int h) {
    return (long long) muls[w + h] * divs[w] % mod * divs[h] % mod;
}

pair<int, int> p[2001];
int ans[2001];

int main() {
    preprocess();
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        p[i].first--;
        p[i].second--;
    }
    p[n] = make_pair(h - 1, w - 1);
    sort(p, p + n);
    for(int i = 0; i <= n; i++)
        ans[i] = comb(p[i].first, p[i].second);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            if(p[i].first <= p[j].first && p[i].second <= p[j].second) {
                int x = (long long) ans[i] * comb(p[j].first - p[i].first, p[j].second - p[i].second) % mod;
                ans[j] = (ans[j] + mod - x) % mod;
            }
    printf("%d\n", ans[n]);
}