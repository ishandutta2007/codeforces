#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd(int x, int y){
    if(!x || !y){
        return x + y;
    }
    return gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ones += (a[i] == 1 ? 1 : 0);
    }
    int len = n + 5;
    for(int i = 0; i < n; ++i){
        int g = a[i];
        if(g == 1){
            len = min(len, 0);
        }
        for(int j = i + 1; j < n; ++j){
            g = gcd(g, a[j]);
            if(g == 1){
                len = min(len, j - i);
                break;
            }
        }
    }
    if(len == 0){
        cout << n - ones << endl;
        return 0;
    }
    if(len == n + 5){
        cout << -1 << endl;
    }else{
        cout << n - 1 + len << endl;
    }

}