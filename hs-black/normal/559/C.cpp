#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int P = 1e9+7;
const int N = 1000500;
const int MAXN = 200500;
int read(void) {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}

ll dp[N], jie[N], inv[N];
ll k, n, m;
void pre_work(void) {
    inv[1] = inv[0] = jie[0] = jie[1] = 1;
    for (ll i = 2;i <= MAXN; i++) {
        jie[i] = jie[i-1] * i % P;
        inv[i] = (P - P / i * inv[P%i] % P) % P;
    }
    for (int i = 1;i <= MAXN; i++) inv[i] = inv[i-1] * inv[i] % P;
}


struct node {
    int x, y;
    bool operator < (const node &i) const {
        if (x != i.x) return x < i.x;
        return y < i.y;
    }
}q[N];

inline ll C(int n,int m) {
    return jie[n] * inv[m] % P * inv[n-m] % P;
}

int main() {
    pre_work();
    n = read(), m = read(), k = read();
    for (int i = 1;i <= k; i++) q[i].x = read(), q[i].y = read();
    q[++k] = (node) {(int)n, (int)m};
    sort(q + 1, q + k + 1);
    for (int i = 1;i <= k; i++) {
        int x = q[i].x, y = q[i].y;
        dp[i] = C(x + y - 2, x - 1);
        for (int j = 1;j < i; j++) 
            if (q[j].y <= y) 
                dp[i] = (dp[i] - C(x + y - q[j].x - q[j].y, x - q[j].x) * dp[j] + P) % P;
    }
    cout << (dp[k] % P + P) % P << endl;
    return 0;
}