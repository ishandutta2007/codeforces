#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll a, b, m;
ll r[55];
ll x[55];
ll Fibonacci[55];
bool f(ll len) {
    ll ret = a * Fibonacci[len-1];
    if(ret > b) return false;
    for(ll index = 2; index <= len; index++) {
        ll factor = Fibonacci[len - index];
        //if(index < len) factor = ((ll)1 << (len - index - 1));
        if(index < len) r[index] = min(m, (b-ret - factor) / factor);
        else r[index] = min(m, (b - ret) / factor);
        if(r[index] <= 0) return false;
        ret += factor * r[index];
        //cerr << index << " " << factor << " " << ret << endl;
    }
    if(ret != b) return false;
    x[1] = a;
    for(ll i = 2; i <= len; i++) {
        x[i] = r[i];
        for(int j = 1; j < i; j++) x[i] += x[j];
    }
    cout << len;
    for(int i = 1; i <= len; i++) cout << " " << x[i];
    cout << endl;
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    Fibonacci[1] = 1;
    Fibonacci[0] = 1;
    for(int i = 2; i <= 52; i++) {
        Fibonacci[i] = 0;//Fibonacci[i-1] + Fibonacci[i-2];
        for(int j = 0; j < i; j++) Fibonacci[i] += Fibonacci[j];
        //cerr << i << " " << Fibonacci[i] << endl;
    }
    ll q;
    cin >> q;
    while(q--) {
        for(int i = 0; i <= 52; i++) r[i] = 0;
        cin >> a >> b >> m;
        bool clear = false;
        if(a == b) {
            cout << "1 " << a << endl;
            continue;
        }
        for(int i = 2; i <= 50; i++) {
            if(a * Fibonacci[i-1] > b) break;
            if(f(i)) {
                clear = true;
                break;
            }
        }
        if(!clear) cout << -1 << endl;
    }
    return 0;
}