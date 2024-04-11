#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll THROW = n + 1;
    ll GET = n;
    ll MOVE = (n-1) + min(k-1, n-k);
    cout << THROW + GET + MOVE << endl;
    return 0;
}