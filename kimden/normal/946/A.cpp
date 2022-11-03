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
    int n;
    cin >> n;
    ll a = 0, b = 0;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(x > 0){
            a += x;
        }else{
            b += -x;
        }
    }
    cout << a + b << endl;



}