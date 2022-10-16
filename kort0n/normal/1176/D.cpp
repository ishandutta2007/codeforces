#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll IsPrime[2800000];
vector<ll> primes;
void init() {
    for(ll i = 2; i < 2800000; i++) IsPrime[i] = true;
    for(ll i = 2; i < 2800000; i++) {
        if(!IsPrime[i]) continue;
        primes.push_back(i);
        for(ll j = i * 2; j < 2800000; j += i) IsPrime[j] = false;
    }
}
multiset<ll> st;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    ll n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i++) {
        ll a;
        cin >> a;
        st.insert(a);
    }
    while(!st.empty()) {
        auto itr = st.end();
        itr--;
        ll now = *itr;
        st.erase(itr);
        if(IsPrime[now]) {
            auto itr2 = lower_bound(primes.begin(), primes.end(), now);
            ll d = distance(primes.begin(), itr2);
            d++;
            cout << d << " ";
            itr = st.lower_bound(d);
            st.erase(itr);
            continue;
        } else {
            ll divisor = 2;
            while(now % divisor != 0) divisor++;
            cout << now << " ";
            itr = st.lower_bound(now / divisor);
            st.erase(itr);
        }
    }
    cout << endl;
    return 0;
}