#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int gcd(int x, int y){
    if(x == 0 || y == 0){
        return x + y;
    }
    return gcd(y, x % y);
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int x;
    int g = k;
    for(int i = 0; i < n; ++i){
        cin >> x;
        g = gcd(g, x);
    }
    cout << (k / g) << endl;
    for(int i = 0; i < k; i += g){
        if(i){
            cout << " ";
        }
        cout << i;
    }
    cout << endl;

    return 0;
}