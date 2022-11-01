#include <cstdio>
#include <algorithm>

using namespace std;

int n, d;
int p[300005];
int cnt[300005];

int memo[30005][505];
bool bio[30005][505];
int dp(int pos, int skok){
    if (pos > 30000) return 0;
    int &r = memo[pos][skok - d + 250];
    if (bio[pos][skok - d + 250]++) return r;
    r = dp(pos + skok + 1, skok + 1);
    r = max(r, dp(pos + skok, skok));
    if (skok != 1) r = max(r, dp(pos + skok - 1, skok - 1));
    r += cnt[pos];
    return r;
}

int main(){
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%d", p + i);
    for (int i = 0; i < n; ++i) ++cnt[p[i]];
    printf("%d\n", dp(d, d));
    return 0;
}