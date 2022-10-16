#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int q;
    cin >> q;
    for(int time = 1; time <= q; time++){
        ll n, m, k;
        cin >> n >> m >> k;
        if(max(n, m) > k){
            cout << -1 << endl;
            continue;
        }
        if((m + n) % 2 == 0){
            if((m % 2) == (k % 2)){
                cout << k << endl;
                continue;
            }
            cout << k - 2 << endl;
            continue;
        }
        cout << k - 1 << endl;
    }

    return 0;
}