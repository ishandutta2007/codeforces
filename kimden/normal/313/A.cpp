#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    cin >> n;
    if(n >= 0){
        cout << n << endl;
        return 0;
    }
    n = -n;
    n = min(n / 10, (n / 100) * 10 + n % 10);
    n = -n;
    cout << n << endl;
    return 0;
}