#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    int a[2], c = 0, flag = 0;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x%2==0 && !flag){cout << 1 << endl << i << endl; flag = 1;}
        else{
            if (c < 2) a[c++] = i;
        }
    }
    if (flag) return;
    if (c == 2) cout << c << endl << a[0] << ' ' << a[1] << endl;
    else cout << -1 << endl;
}

int main(){
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}