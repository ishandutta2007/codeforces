#include <cstdio>
#include <iterator>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
constexpr int mod = 1000000007;
int fac[1000001];
vector<int> vec[1000000];
int main() {
    fac[0] = 1;
    for(int i = 1; i <= 1000000; i++)
        fac[i] = (long long) fac[i - 1] * i % mod;

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        int g;
        scanf("%d", &g);
        for(int j = 0; j < g; j++) {
            int x;
            scanf("%d", &x);
            x--;
            vec[x].push_back(i);
        }
    }
    sort(vec, vec + m);
    int ans = 1;
    for(int i = 0, cnt = 0; i < m; i++) {
        cnt++;
        if(i == m - 1 || vec[i] != vec[i + 1]) {
            ans = (long long) ans * fac[cnt] % mod;
            cnt = 0;
        }
    }
    printf("%d\n", ans);
}