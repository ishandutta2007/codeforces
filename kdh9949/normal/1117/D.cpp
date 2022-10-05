#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 105;
const ll M = ll(1e9) + 7;

struct Mat{
    ll a[N][N];
    Mat operator*(const Mat &o){
        Mat r;
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
            r.a[i][j] = 0;
            for(int k = 0; k < N; k++) r.a[i][j] += a[i][k] * o.a[k][j] % M;
            r.a[i][j] %= M;
        }
        return r;
    }
} V;

Mat pw(Mat x, ll y){
    if(y == 1) return x;
    if(y & 1) return pw(x * x, y / 2) * x;
    return pw(x * x, y / 2);
}

ll n;
int m;

int main(){
    scanf("%lld%d", &n, &m);
    V.a[0][0] = V.a[0][m - 1] = 1;
    for(int i = 1; i < m; i++) V.a[i][i - 1] = 1;
    V = pw(V, n);
    printf("%lld\n", V.a[0][0]);
}