#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5];
int b[N+5];

void solve(){
    int resl = 0, resr = N;
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], b[i] = a[i];
    sort(a+1, a+1+n);
    int t = (n+k+1)/2;
    for(int i=t; i<=n; i++){
        if(resr - resl > a[i] - a[i-t+1]) resl = a[i-t+1], resr = a[i];
    }
    cout << resl << " " << resr << "\n";
    int tr = 0;
    int sl = 1, L = 1;
    for(int i=1; i<=n; i++){
        if(resl <= b[i] && b[i] <= resr) tr++;
        else tr--;
        if(tr == sl && sl != k){
            sl++;
            cout << L << " " << i << "\n";
            L = i + 1;
        }
    }
    cout << L << " " << n << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}