#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        cout << a[n-1] + a[n] << "\n";
    }
    return 0;
}