#include <iostream>
#include <cstdio>
using namespace std;


#define N 8000
#define LL long long
int mod = 1e9+9;


int C[N][N];
int f[N];
void init() {
    for(int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if(C[i][j] >= mod) C[i][j] -= mod;
        }
    }
    f[0] = 1;
    for(int i = 1; i < N; ++i) f[i] = 1LL * f[i-1] * i % mod;
}

int n, w, b;

int main() {
	//freopen("306C.txt","r",stdin);
    init();
    cin >> n >> w >> b;
    int ans = 0;
    for(int i = 1; i <= w - 1; ++i) {
        ans += 1LL * C[w+b-3][n-3] * C[w][i] % mod * f[i] % mod * f[b] % mod * f[w-i] % mod;
        if(ans >= mod) ans -= mod;
    }
    cout << ans << endl;
    return 0;
}