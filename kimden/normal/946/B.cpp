#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    while(1){
        if(n == 0 || m == 0){
            break;
        }
        if(n >= 2 * m){
            n %= 2 * m;
        }else if(m >= 2 * n){
            m %= 2 * n;
        }else{
            break;
        }
    }
    cout << n << " " << m << endl;



}