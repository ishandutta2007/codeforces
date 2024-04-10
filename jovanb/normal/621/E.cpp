#include <bits/stdc++.h>
using namespace std;

int x;

const int MOD = 1000000007;

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int add(int a, int b){
    return (a + b)%MOD;
}

struct matrix{
    int mat[100][100];
    matrix operator *(const matrix &b){
        matrix res;
        for(int i=0; i<x; i++){
            for(int j=0; j<x; j++){
                res.mat[i][j] = 0;
                for(int k=0; k<x; k++){
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], b.mat[k][j]));
                }
            }
        }
        return res;
    }
};

matrix mat;

matrix pw(matrix a, int b){
    if(b == 1) return a;
    matrix res = pw(a, b/2);
    res = res * res;
    if(b%2) res = res * a;
    return res;
}

int niz[100005];

int main(){

    int n, b, k;
    cin >> n >> b >> k >> x;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        for(int j=0; j<x; j++){
            mat.mat[j][(10*j+niz[i])%x]++;
        }
    }
    /*for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            cout << mat.mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    if(b == 1){
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += (k == niz[i]%x);
        }
        cout << sum;
        return 0;
    }
    mat = pw(mat, b-1);
    /*for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            cout << mat.mat[i][j] << " ";
        }
        cout << endl;
    }*/
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum = add(sum, mat.mat[niz[i]%x][k]);
    }
    cout << sum;
    return 0;
}