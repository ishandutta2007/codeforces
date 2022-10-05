#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

char input[100010];
int n, m, c, mc = 1e7, dp[2010][4030], dp2[2010][4030];
int BOJ = 2010;
bool chk[2010][4030], chk2[2010][4030];
ll mod = 1000000007;
ll ans;

ll f(int len, int cnt){
    if(len < abs(cnt)) return 0;
    if(cnt < 0) return 0;
    if(len == 0) return (cnt == 0);
    if(chk[len][cnt + BOJ]) return dp[len][cnt + BOJ];
    ll ret = f(len - 1, cnt - 1) + f(len - 1, cnt + 1);
    chk[len][cnt + BOJ] = true;
    return dp[len][cnt + BOJ] = ret % mod;
}

ll f2(int len, int cnt){
    if(len < abs(cnt)) return 0;
    if(len == 0) return (cnt == 0);
    if(chk2[len][cnt + BOJ]) return dp2[len][cnt + BOJ];
    ll ret = f2(len - 1, cnt - 1) + f2(len - 1, cnt + 1);
    chk2[len][cnt + BOJ] = true;
    return dp2[len][cnt + BOJ] = ret % mod;

}

int main(){
    scanf("%d%d%s", &n, &m, input);
    n -= m;
    for(int i = 0; i < m; i++){
        c += (input[i] == '(') ? 1 : -1;
        mc = min(mc, c);
    }
    for(int i = 0; i <= n; i++){
        for(int j = max(0, -mc); j <= n; j++){
            ans += f(i, j) * f(n - i, c + j);
            ans %= mod;
        }
    }
    printf("%I64d", ans);
}