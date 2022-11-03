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
    int n, t;
    cin >> n >> t;
    if(n == 1 && t == 10){
        cout << -1 << endl;
        return 0;
    }
    if(t == 10){
        t = 1;
    }
    cout << t;
    for(int i = 0; i < n - 1; i++){
        cout << 0;
    }
    cout << endl;
    return 0;
}