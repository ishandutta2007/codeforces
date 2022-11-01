#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int f[34][(int) 1e5], m[34][(int) 1e5];
long long s[34][(int) 1e5];
int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", f[0] + i);
    for(int i = 0; i < n; i++)
        scanf("%d", m[0] + i), s[0][i] = m[0][i];
    for(int j = 1; (1LL << j) <= k; j++) {
        for(int i = 0; i < n; i++) {
            int x = f[j - 1][i];
            f[j][i] = f[j - 1][x];
            s[j][i] = s[j - 1][i] + s[j - 1][x];
            m[j][i] = min(m[j - 1][i], m[j - 1][x]);
        }
    }
    for(int i = 0; i < n; i++) {
        int x = i, mn = (int) 1e8;
        long long sm = 0;
        for(int j = 0; (1LL << j) <= k; j++)
            if(k & (1LL << j)) {
                sm += s[j][x];
                mn = min(mn, m[j][x]);
                x = f[j][x];
            }
        printf("%lld %d\n", sm, mn);
    }
}