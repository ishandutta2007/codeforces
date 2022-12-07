#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000005;
const long long INF = 100000000000000000LL;

int n, a, b;

int gcd(int a, int b) {
    return gcd(b, a % b);
}

vector<int> fac;
int x[N];

void getfac(int x) {
    int m = sqrt(x + 0.5);
    for (int i = 2; i <= m; i++) {
        if (x % i == 0) {
            fac.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) fac.push_back(x);
}

long long pre[N];

long long cal(int d) {
    for (int i = 1; i <= n; i++) pre[i] = INF;
    long long u = 0;
    for (int i = 1; i <= n; i++) {
        u -= a;
        if (x[i] % d != 0) {
            if ((x[i] + 1) % d != 0 && (x[i] - 1) % d != 0) {
                for (int j = i; j <= n; j++)
                    pre[j] = pre[j - 1];
                break;
            }
            u += b;
        }
        pre[i] = min(pre[i - 1], u);
    }
    u = 0;
    long long ans = pre[n] + 1LL * a * n;
    for (int i = n; i >= 1; i--) {
        u -= a;
        if (x[i] % d != 0) {
            if ((x[i] + 1) % d != 0 && (x[i] - 1) % d != 0) break;
            u += b;
        }
        ans = min(ans, u + pre[i - 1] + 1LL * a * n);
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    getfac(x[1]); getfac(x[1] - 1); getfac(x[1] + 1);
    getfac(x[n]); getfac(x[n] - 1); getfac(x[n] + 1);
    sort(fac.begin(), fac.end());
    vector<int>::iterator it = unique(fac.begin(), fac.end());
    fac.erase(it, fac.end());
    long long ans = 1LL * a * (n - 1);
    for (int i = 0; i < fac.size(); i++)
        ans = min(ans, cal(fac[i]));
    printf("%lld\n", ans);
    return 0;
}