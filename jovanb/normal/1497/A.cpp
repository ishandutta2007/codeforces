#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[100005];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    vector <int> vec;
    for(int i=1; i<=n; i++){
        if(i > 1 && a[i] == a[i-1]) vec.push_back(a[i]);
        else cout << a[i] << " ";
    }
    for(auto c : vec) cout << c << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}