#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int a[505];
int dpl[1005][1005];
int dpr[1005][1005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        char c;
        cin >> c;
        if(c == '-') a[i] = -1;
        else cin >> a[i];
    }
    int res = 0;
    for(int tr=1; tr<=n; tr++){
        if(a[tr] == -1) continue;
        for(int i=0; i<=n+5; i++){
            for(int j=0; j<=n+5; j++){
                dpl[i][j] = dpr[i][j] = 0;
            }
        }
        dpl[0][0] = 1;
        for(int i=1; i<tr; i++){
            if(a[i] == -1){
                for(int j=0; j<tr; j++){
                    dpl[i][j] = add(dpl[i][j], dpl[i-1][j]);
                }
                for(int j=0; j<tr; j++){
                    dpl[i][j] = add(dpl[i][j], dpl[i-1][j+1]);
                }
                dpl[i][0] = add(dpl[i][0], dpl[i-1][0]);
            }
            else{
                if(a[i] <= a[tr]){
                    for(int j=0; j<tr; j++){
                        dpl[i][j] = add(dpl[i][j], dpl[i-1][j]);
                    }
                    for(int j=1; j<tr; j++){
                        dpl[i][j] = add(dpl[i][j], dpl[i-1][j-1]);
                    }
                }
                else{
                    for(int j=0; j<tr; j++){
                        dpl[i][j] = add(dpl[i][j], mul(2, dpl[i-1][j]));
                    }
                }
            }
        }
        for(int j=0; j<=n; j++){
            dpr[tr][j] = dpl[tr-1][j];
        }
        for(int i=tr+1; i<=n; i++){
            if(a[i] == -1){
                for(int j=0; j<=n; j++) dpr[i][j] = add(dpr[i][j], dpr[i-1][j]);
                for(int j=0; j<=n; j++) dpr[i][j] = add(dpr[i][j], dpr[i-1][j+1]);
            }
            else{
                if(a[i] < a[tr]){
                    for(int j=1; j<=n; j++){
                        dpr[i][j] = add(dpr[i][j], dpr[i-1][j-1]);
                    }
                    for(int j=0; j<=n; j++){
                        dpr[i][j] = add(dpr[i][j], dpr[i-1][j]);
                    }
                }
                else{
                    for(int j=0; j<=n; j++){
                        dpr[i][j] = add(dpr[i][j], mul(2, dpr[i-1][j]));
                    }
                }
            }
        }
        int sum = 0;
        for(int j=0; j<=n; j++) sum = add(sum, dpr[n][j]);
        res = add(res, mul(a[tr], sum));
    }
    cout << res << "\n";
    return 0;
}

/*
4
-
+ 1
+ 1
-
*/