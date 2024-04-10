#include <bits/stdc++.h>
using namespace std;

int g(int x){
    int r = 1;
    if(x < 10) return x;
    else while(x > 0){
        if(x%10 != 0) r *= x%10;
        x /= 10;
    }
    return g(r);
}

int sum[10][1000005];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    for(int k=1; k<=9; k++){
        for(int i=1; i<=1000000; i++){
            sum[k][i] = sum[k][i-1];
            if(g(i) == k) sum[k][i]++;
        }
    }
    int q, l, r, k;
    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        cout << sum[k][r] - sum[k][l-1] << "\n";
    }
    return 0;
}