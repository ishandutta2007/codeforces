#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
int mindiv[10000001];
ll N;
ll gcdnum[10000001];
ll ans = 0;
ll mindivnum[10000001];
ll mindivsum[10000002];

int main() {
    cin >> N;
    vector<ll> primes;
    ll composite = 0;
    for(int i = 1; i <= N; i++) {
        mindiv[i] = -1;
    }
    mindiv[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(mindiv[i] != -1) {
            composite++;
            continue;
        }
        if(i * 2 <= N) primes.push_back(i);
        for(int j = i * 2; j <= N; j += i) {
            if(mindiv[j] == -1) mindiv[j] = i;
        }
    }
    for(int i = 2; i <= N; i++) {
        if(mindiv[i] == -1) continue;
        mindivnum[mindiv[i]]++;
    }
    for(int i = 1; i <= N; i++) {
        mindivsum[i+1] = mindivsum[i] + mindivnum[i];
    }
    ans = (ll)primes.size() * ((ll)primes.size() - 1) * 2;
    //cerr << "default: " << ans << endl;
    for(int i = 0; i < primes.size(); i++) {
        ll tmp = N / primes[i] + 1;
        //cerr << primes[i] << " " << tmp << endl;
        auto itr = lower_bound(primes.begin(), primes.end(), tmp);
        ll num = distance(itr, primes.end());
        ans += num;
        if(primes[i] * primes[i] > N) ans--;
        //cerr << primes[i] << " " << ans << endl;
    }
    ans /= 2;
    //cerr << ans << endl;
    gcdnum[1] = composite * (composite - 1) / 2;
    for(ll i = 2; i <= N; i++) {
        ll num = N / i;
        if(mindiv[i] == -1) num--;
        gcdnum[i] = num * (num - 1) / 2;
    }
    for(ll i = N; i >= 1; i--) {
        for(ll j = i * 2; j <= N; j += i) {
            gcdnum[i] -= gcdnum[j];
        }
    }
    ans += composite * (composite - 1) / 2;
    ans += gcdnum[1];
    //cerr << ans << endl;
    for(auto p : primes) {
        ans += 3 * composite;
        ll f = N / p;
        ans -= mindivsum[f + 1];
        ans -= (N / p) - 1;
        //cerr << p << " " << ans << endl;
    }
    //cerr << ans << endl;
    cout << ans << endl;
    return 0;
}