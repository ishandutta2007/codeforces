#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

struct Matrix{
    int mat[N+5][N+5];
    int n;
    Matrix(int _n){ n = _n; for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) mat[i][j] = 0; }
    Matrix operator *(const Matrix &b){
        Matrix res(n);
        for(int i=0; i<=n; i++){
            for(int k=0; k<=n; k++){
                for(int j=0; j<=n; j++){
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], b.mat[k][j]));
                }
            }
        }
        return res;
    }
};

Matrix pwmat(const Matrix &a, int b){
    if(b == 1) return a;
    Matrix res = pwmat(a, b/2);
    res = res*res;
    if(b%2) res = res*a;
    return res;
}

int a[N+5];
int b[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+1+n);
    int cnt = 0, db = 0;
    for(int i=1; i<=n; i++){
        if(b[i] == 0 && a[i] == 0) db++;
        if(a[i] == 0) cnt++;
    }
    Matrix step(cnt);
    int svi = pw(n*(n-1)/2, MOD - 2);
    for(int c00=0; c00<=cnt; c00++){
        int c01 = cnt - c00;
        int c10 = c01;
        int c11 = n - c00 - c01 - c10;
        step.mat[c00][c00] = 1;
        if(c01 > 0 && c10 > 0) step.mat[c00][c00+1] = mul(mul(c01, c10), svi), step.mat[c00][c00] = sub(step.mat[c00][c00], step.mat[c00][c00+1]);
        if(c00 > 0 && c11 > 0) step.mat[c00][c00-1] = mul(mul(c00, c11), svi), step.mat[c00][c00] = sub(step.mat[c00][c00], step.mat[c00][c00-1]);
    }
    step = pwmat(step, k);
    cout << step.mat[db][cnt] << "\n";
    return 0;
}