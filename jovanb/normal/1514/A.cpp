#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[105];

bool solve(){
    int n;
    cin >> n;
    bool ima = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        int x = sqrt(a[i]);
        if(x*x != a[i]) ima = 1;
    }
    if(ima) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}