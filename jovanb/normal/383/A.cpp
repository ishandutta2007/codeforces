#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll res = 0, sum = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x) sum++;
        else res += sum;
    }
    cout << res;
    return 0;
}