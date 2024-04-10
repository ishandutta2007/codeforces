#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
int a[200005];
int pr[200005];

bool check(int g){
    int mn = 0;
    for(int i=1; i<=n; i++){
        pr[i] = pr[i-1];
        if(a[i] >= g) pr[i]++;
        else pr[i]--;
        if(i >= k) mn = min(mn, pr[i-k]);
        if(i >= k && pr[i] > mn) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int l = 1, r = n, res = 1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            res = max(res, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res << "\n";
    return 0;
}