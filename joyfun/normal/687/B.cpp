#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
vector<int> prime[N], cnt[N];
int vis[N];
vector<int> sb;
int use[105];
int main() {
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        for (int j = i; j < N; j += i) {
            prime[j].push_back(i);
            vis[j] = 1;
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < prime[k].size(); i++) {
        int s = 1;
        while (k % (1LL * s * prime[k][i]) == 0) s *= prime[k][i];
        sb.push_back(s);
    }
    int x;
    while (n--) {
        scanf("%d", &x);
        for (int i = 0; i < sb.size(); i++) {
            if (x % sb[i] == 0) use[i] = 1;
        }
    }
    int f = 1;
    for (int i = 0; i < sb.size(); i++)
        if (use[i] == 0) f = 0;
    printf("%s\n", f ? "Yes" : "No");
    return 0;
}