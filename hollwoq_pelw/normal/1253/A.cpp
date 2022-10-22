#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n],k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {cin >> k; a[i] = k - a[i];}
    int l = 0, r = n-1;
    while(a[l] == 0 && l != r) l ++;
    while(a[r] == 0 && l != r) r --;
    for (int i = l; i <= r; i++){
        if (a[i] != a[l] || a[i] < 0){cout << "NO" << endl; return;}
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        solve();
    }
}