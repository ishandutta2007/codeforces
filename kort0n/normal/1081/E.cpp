#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
//#define PI (aocos(-1))

ll sq(ll in){
    ll ok = 0;
    ll ng = in;
    if(in > 1e9) ng = 1e9;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(mid * mid <= in){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    ll x[200500];
    for(int i = 2; i <= n; i += 2){
        //cin >> x[i];
        scanf("%lld", &x[i]);
    }
    ll now = 0;
    for(int j = 1; j <= n; j += 2){
        for(ll beta = now + 1; ; beta++){
            if(2 * beta + 1 > x[j + 1]){
                cout << "No" << endl;
                return 0;
            }
            ll alpha = sq(beta * beta + x[j + 1]);
            //cout << beta << " " << x[j + 1] << " " << alpha << endl;
            if((alpha * alpha) != (beta * beta + x[j + 1])) continue;
            x[j] = beta * beta - now * now;
            if(x[j] > 1e13) continue;
            now = alpha;
            break;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++){
        cout << x[i];
        if(i < n) cout << " ";
    }
    cout << endl;
    return 0;
}