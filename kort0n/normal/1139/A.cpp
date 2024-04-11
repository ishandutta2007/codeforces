#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string S;
int n;

bool iseven(int i) {
    if(S[i] == '0' || S[i] == '2' || S[i] == '4' || S[i] == '6' || S[i] == '8') return true;
    else return false;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> S;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(iseven(i)) ans += i + 1;
    }
    cout << ans << endl;
    return 0;
}