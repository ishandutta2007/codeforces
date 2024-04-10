#include <cstdio>
#include <bitset>
using namespace std;

constexpr int module = 1000000007;

int p2[1000000];
int dp[21][1048576];

inline void adjust(int& x) {
    if(x >= module)
        x -= module;
}

int main(){
    int n;
    scanf("%d", &n);
    p2[0] = 1;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        dp[0][a]++;
        adjust(p2[i + 1] = p2[i] << 1);
    }
    int add = 0, minu = 0;
    for(int i = 1048575; i >= 0; i--) {
        for(int d = 0; d < 20; d++) {
            if((i >> d) & 1)
                dp[d + 1][i] = dp[d][i];
            else
                adjust(dp[d + 1][i] = dp[d][i] + dp[d][i + (1 << d)]);
        }
        if(bitset<20>(i).count() & 1)
            adjust(minu += p2[dp[20][i]]);
        else
            adjust(add += p2[dp[20][i]]);
    }
    add -= minu;
    if(add < 0)
        add += module;
    printf("%d\n", add);
}