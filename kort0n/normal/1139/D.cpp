#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b % 2 == 1) ret = ret * a % mod;
    return ret;
}

ll Inv[1000500];
ll m;
ll dp[100050];
ll num[1000];
vector<ll> primes;

void fill(int now) {
    vector<int> primetable;
    int copy = now;
    for(int i = 0; i < primes.size(); i++) {
        if(copy == 1) break;
        if(primes[i] * primes[i] > copy) {
            primetable.push_back(copy);
            break;
        }
        if(copy % (primes[i]*primes[i]) == 0) {
            dp[now] = dp[now / primes[i]];
            //cerr << now << " is equal to " << now / primes[i] << endl;
            return;
        }
        if(copy % primes[i] == 0) {
            primetable.push_back(primes[i]);
            copy /= primes[i];
        }
    }
    /*
    cout << now << endl;
    for(int i = 0; i < primetable.size(); i++) cerr << primetable[i] << " ";
    cerr << endl;
    */
    dp[now] = 1;
    int SIZE = primetable.size();
    for(int bits = 0; bits < (1<<SIZE); bits++) num[bits] = 0;
    for(int bits = (1<<SIZE) - 1; bits > 0; bits--) {
        int val = 1;
        for(int i = 0; i < SIZE; i++) {
            if((bits >> i) & 1) val *= primetable[i];
        }
        int div_num = m / val;
        for(int bits2 = ((1<<SIZE)-1)&bits; bits2 > 0; bits2 = (bits2 - 1)&bits) {
            //cerr << bits << " " << bits2 << endl;
            int val2 = 1;
            int XOR_num = 0;
            for(int i = 0; i < SIZE; i++) {
                if((bits2 >> i) & 1) val2 *= primetable[i];
                if(((bits >> i) & 1) ^ ((bits2 >> i) & 1)) XOR_num++;
            }
            if(XOR_num % 2 == 0) num[bits2] += div_num;
            else num[bits2] -= div_num;
        }
        ll Add = num[bits] * Inv[m] % mod;
        //cerr << now << " "<< val << " " << num[bits] << endl;
        Add = (Add * dp[val]) % mod;
        if(val == now) continue;
        dp[now] = (dp[now] + Add) % mod;
    }
    ll probability = (m - num[(1<<SIZE)-1]) * Inv[m] % mod;
    //cerr << m << " "<< num[(1<<SIZE)-1] << " "<< probability << endl;
    dp[now] = dp[now] * beki(probability, mod - 2) % mod;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m;
    for(ll i = 1; i <= 1000000; i++) {
        Inv[i] = beki(i, mod - 2);
    }
    for(ll i = 2; i <= 100000; i++) {
        bool ok = true;
        for(ll j = 0; j < primes.size(); j++) {
            if(i % primes[j] == 0) {
                ok = false;
                break;
            }
            if(primes[j] * primes[j] > i) break;
        }
        if(ok) primes.push_back(i);
    }
    dp[0] = 0;
    ll ans = 0;
    for(ll now = 2; now <= m; now++) {
        fill(now);
        //cout << now << " " << dp[now] << endl;
        ans = (ans + dp[now]) % mod;
    }
    ans =  ans * Inv[m] % mod;
    cout << (ans + 1) % mod << endl;
    return 0;
}