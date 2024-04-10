#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int a[N+5];
int s[N+5];

void solve(){
    int n, q;
    cin >> n >> q;
    int t = q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        if(t <= 0) break;
        if(a[i] > t){
            t--;
        }
        if(i == n){
            for(int j=1; j<=n; j++) cout << "1";
            cout << "\n";
            return;
        }
    }
    int x = 0;
    for(int i=n; i>=1; i--){
        if(x == q){
            if(a[i] > q){
                s[i] = 0;
            }
            else s[i] = 1;
        }
        else{
            s[i] = 1;
            if(a[i] > x) x++;
        }
    }
    for(int i=1; i<=n; i++) cout << s[i];
    cout << "\n";
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

/*
1
5 1
5 4 3 2 1
*/