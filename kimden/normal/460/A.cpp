#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 300002;
ll t[MAXN], w[MAXN], num[MAXN];
map<ll, ll> st;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    while(n >= m){
        n -= m-1;
        ans += m;
    }
    ans += n;
    cout << ans;
    return 0;
}