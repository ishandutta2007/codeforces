#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
bool field[1000005];
ll m, a, b;
ll ans, now;
ll ind = 1;
ll GCD(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return GCD(b, a % b);
}

void Search(int pos) {
    if(pos < 0 || pos > ind) return;
    if(field[pos]) return;
    //cerr << "SEARCHING " << pos << endl;
    if((pos-a < 0 || pos-a > ind || !field[pos-a]) && (pos+b < 0 || pos+b > ind || !field[pos+b])) return;
    field[pos] = true;
    now++;
    Search(pos+a);
    Search(pos-b);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m >> a >> b;
    ll gcd = GCD(a, b);
    ans = 1;
    now = 1;
    field[0] = true;
    while(ind <= m) {
        Search(ind);
        ans += now;
        cerr << ind << " " << now << endl;
        if(field[ind]) {
            if((ind + 1 + gcd - 1) / gcd == now) break;
        }
        ind++;
        /*
        if(ind % gcd == 0) {
            if(ind / gcd == now) break;
        }
        */
    }
    if(ind == (m + 1)) {
        cout << ans << endl;
        return 0;
    }
    ans -= now;
    //ind--;
    ll before = ind;
    ll after = (m / gcd) * gcd - 1;
    ll val = (before / gcd + after / gcd + 2);
    ll num = (after - before + 1) / gcd;
    cerr << ans << endl;
    if(num > 0) ans += num * val * gcd / 2;
    cerr << ans << endl;
    cerr << before << " " << after << " " << num << " " << val << endl;
    for(ll i = after + 1; i <= m; i++) {
        ans += i / gcd + 1;
    }
    cout << ans << endl;
    return 0;
}