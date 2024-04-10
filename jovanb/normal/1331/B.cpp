#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    
    int n;
    cin >> n;
    int res = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0) res = i;
    }
    cout << res << n/res;
    return 0;
}