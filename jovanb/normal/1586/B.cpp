#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

bool ima[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) ima[i] = 0;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        ima[b] = 1;
    }
    for(int i=1; i<=n; i++){
        if(!ima[i]){
            for(int j=1; j<=n; j++){
                if(j == i) continue;
                cout << i << " " << j << "\n";
            }
            return;
        }
    }
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