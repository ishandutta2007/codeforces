#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5];
ll pref[N+5];
int nxt[N+5][30];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i], pref[i] = pref[i-1] + a[i];
    for(int j=0; j<=29; j++) nxt[n+1][j] = n + 1;
    for(int i=n; i>=1; i--){
        for(int j=29; j>=0; j--) nxt[i][j] = nxt[i+1][j];
        for(int j=29; j>=0; j--){
            if(j < 29) nxt[i][j] = min(nxt[i][j], nxt[i][j+1]);
            if((1 << j) & a[i]) nxt[i][j] = i;
        }
    }
    ll res = 0;
    for(int i=2; i<n; i++){
        ll x = a[i-1];
        ll lim = 0;
        for(int j=30; j>=1; j--){
            if((1 << (j-1)) & x){
                lim = (1 << j);
                break;
            }
        }
        int j = i;
        ll sum = a[j];
        while(j < n && sum < lim){
            if((x ^ a[j+1]) == sum) res++;
            j++;
            sum += a[j];
        }
        while(j < n && sum < (1 << 30)){
            int d;
            for(d=29; d>=0; d--){
                if((1 << d) & sum){
                    break;
                }
            }
            int k = nxt[j + 1][d];
            if(k > n) break;
            if((x ^ a[k]) == pref[k-1] - pref[i-1]) res++;
            sum = pref[k] - pref[i-1];
            j = k;
        }
    }
    cout << res << "\n";
    return 0;
}