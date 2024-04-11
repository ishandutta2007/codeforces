#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll n, m, k;
    cin >> n >> m >> k;
    if(((n * m * 2) % k) != 0){
        cout << "NO" << endl;
        return 0;
    }
    if(k == 2){
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
        return 0;
    }
    bool checker = false;
    ll target = n * m * 2 / k;
    if(n > m){
        checker = true;
        swap(n, m);
    }
    ll x[3];
    ll y[3];
    x[0] = 0;
    y[0] = 0;
    x[1] = 1;
    x[2] = n;
    y[2] = n - (target % n);
    y[1] = (target + y[2]) / n;
    if(checker){
        for(int i = 1; i <= 2; i++){
            swap(x[i], y[i]);
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < 3; i++){
        cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}