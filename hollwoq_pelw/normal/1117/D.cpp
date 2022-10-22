#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
#define Mat vector<vector<int>>

Mat operator * (const Mat &a, const Mat &b){
    Mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b[0].size(); j++){
            for (int k = 0; k < a[0].size(); k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

int n, m;

Mat binpow(Mat a, int x){
    Mat r(n, vector<int>(n));;
    for (int i = 0; i < n; i++){
        r[i][i] = 1;
    }
    while(x){
        if (x & 1) r = r * a; 
        x >>= 1;   a = a * a;
    }
    return r;
}


signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;
    Mat b(n, vector<int>(n));
    for (int i = 0; i + 1 < n; i++){
        b[i + 1][i] = 1;
    }
    b[n - 1][n - 1] = b[0][n - 1] = 1;
    cout << binpow(b, m)[n - 1][n - 1];
    }