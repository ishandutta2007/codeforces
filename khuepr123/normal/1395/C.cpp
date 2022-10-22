#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m; cin >> n >> m;
    int A[n], B[m];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int j = 0; j < m; j++){
        cin >> B[j];
    }
    sort(B, B + m);
    bool a[n][9]; bool b[m][9]; bool x[n][m][9]; bool ck[n][m]; bool f[9]; bool v;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < 9; k++){
            a[i][k] = A[i] % 2;
            A[i] = A[i] / 2;
        }
    }
    for(int j = 0; j < m; j++){
        for(int k = 0; k < 9; k++){
            b[j][k] = B[j] % 2;
            B[j] = B[j] / 2;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 9; k++){
                x[i][j][k] = a[i][k] && b[j][k];
                ck[i][j] = 1;
            }
        }
    }
    for(int k = 8; k > -1; k--){
        f[k] = 1; v = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ck[i][j]){
                    f[k] = f[k] && x[i][j][k];
                }
            }
            if(f[k]){
                v = 1; break;
            }
            f[k] = 1;
        }
        if(v){
            continue;
        }
        f[k] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ck[i][j]){
                    if(x[i][j][k]){
                        ck[i][j] = 0;
                    }
                }
            }
        }
        
    }
    int sum = 0; int h = 256;
    for(int k = 8; k > -1; k--){
        sum = sum + (f[k] * h);
        h = h / 2;
    }
    cout << sum;
}