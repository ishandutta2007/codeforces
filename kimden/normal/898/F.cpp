#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll binpow(ll x, ll p, ll mod){
    ll ans = 1;
    while(p){
        if(p & 1LL){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        p >>= 1LL;
    }
    return ans;
}

string s;

vector<vector<int>> degs, pref;
vector<int> mods = {1000000007};
vector<int> roots;
int n, k;

void output(int j, int jj){
    for(int i = 0; i < n; ++i){
        if(i == j){
            cout << '+';
        }
        if(i == jj){
            cout << '=';
        }
        cout << s[i];
    }
    cout << endl;
}

bool check(int i1, int i2) {
    if(s[0] == '0' && i1 > 1){
        return false;
    }
    if(s[i1] == '0' && i2 > 1 + i1){
        return false;
    }
    if(s[i2] == '0' && n > 1 + i2){
        return false;
    }
    for(int j = 0; j < k; ++j){
        ll x = ((pref[j][i1] + mods[j] - pref[j][0]) % mods[j] * ll(degs[j][n - i1])) % mods[j];
        ll y = ((pref[j][i2] + mods[j] - pref[j][i1]) % mods[j] * ll(degs[j][n - i2])) % mods[j];
        ll z = ((pref[j][n] + mods[j] - pref[j][i2]) % mods[j] * ll(degs[j][0])) % mods[j];
        if(((x + y) % mods[j] + (mods[j] - z)) % mods[j] != 0){
            return false;
        }
    }
    output(i1, i2);
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cin >> s;
    n = s.length();
    k = mods.size();
    degs.resize(k, vector<int>(n + 1));
    pref.resize(k, vector<int>(n + 1));
    roots.resize(k);
    for(int i = 0; i < k; ++i){
        roots[i] = binpow(10, mods[i] - 2, mods[i]);
    }
    for(int j = 0; j < k; ++j){
        degs[j][0] = 1;
        pref[j][0] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            degs[j][i] = (degs[j][i - 1] * ll(roots[j])) % mods[j];
            pref[j][i] = (pref[j][i - 1] + degs[j][i] * ll(s[i - 1] - '0')) % mods[j];
        }
    }
    if(n % 3 == 0){
        check(n / 3, 2 * n / 3);
    }
    if(n % 3 == 1){
        check(n / 3, 2 * (n / 3));
    }
    for(int i = 1; n > 2 * i + 1; ++i){
        check(i, n - i - 1);
        check(n - 2 * i - 1, n - i - 1);
    }
    for(int i = 1; n > 2 * i; ++i){
        check(i, n - i);
        check(n - 2 * i, n - i);
    }
}