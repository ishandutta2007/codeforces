#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;

ll niz[100005];
ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    return (a*b)%MOD;
}

struct matrix{
    ll mat[2][2];
    matrix operator *(const matrix &b){
        matrix res;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                res.mat[i][j] = 0;
                for(int k=0; k<2; k++){
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], b.mat[k][j]));
                }
            }
        }
        return res;
    }
};

matrix mat;

ll pw(ll a, ll b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

matrix pwm(matrix a, ll b){
    if(b == 1) return a;
    matrix res = pwm(a, b/2);
    res = res * res;
    if(b%2) res = res * a;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    bool jedan = 1;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        if(niz[i] > 1) jedan = 0;
    }
    if(jedan){
        cout << "0/1";
        return 0;
    }
    ll y = 2;
    matrix res;
    res.mat[0][0] = 1;
    res.mat[0][1] = 2;
    res.mat[1][0] = 1;
    res.mat[1][1] = 0;
    for(int i=1; i<=n; i++){
        y = pw(y, niz[i]);
        res = pwm(res, niz[i]);
    }
    ll d = pw(2, MOD-2);
    y = mul(y, d);
    /*for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << res.mat[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << mul(res.mat[1][1], d) << "/" << y << "\n";
    return 0;
}