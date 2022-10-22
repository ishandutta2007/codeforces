#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mn = 0, mx = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(!mn || a[mn] > a[i]) mn = i;
            if(!mx || a[mx] < a[i]) mx = i;
        }
        cout << mn << " " << mx << "\n";
    }
    return 0;
}