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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
vector<ll> grundy[3];
const int MAX = 1000;

ll Hash(ll a) {
    ll bits = 0;
    for(ll i = 0; i < 5; i++) {
        for(ll j = 0; j < 3; j++) {
            ll factor = (1LL << (2 * (3*i+j)));
            bits += factor * grundy[j][a+i];
        }
    }
    //cerr << "hash: " << a << " " << bits << endl;
    return bits;
}

ll f(ll rest, ll idx, ll loop) {
    if(rest <= 0) return 0;
    if(rest <= MAX) return grundy[idx][rest];
    ll val = rest - MAX;
    rest -= loop * (val / loop);
    return grundy[idx][rest];
}

void solve() {
    ll N, x[3];
    cin >> N;
    for(int i = 0; i < 3; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= MAX * 2; i++) {
        for(int j = 0; j < 3; j++) {
            vector<ll> v;
            for(int k = 0; k < 3; k++) {
                if(j > 0 and j == k) continue;
                if(x[k] > i) v.push_back(0);
                else v.push_back(grundy[k][i-x[k]]);
            }
            v.push_back(1e9);
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            for(int k = 0; ; k++) {
                if(v[k] != k) {
                    grundy[j][i] = k;
                    break;
                }
            }
        }
        /*
        cerr << i << ":";
        for(int j = 0; j < 3; j++) {
            cerr << " " << grundy[j][i];
        }
        cerr << endl;
        */
    }
    ll base = Hash(MAX);
    ll loop = -1;
    for(ll i = MAX + 1; i <= 2 * MAX; i++) {
        if(Hash(i) == base) {
            loop = i - MAX;
            break;
        }
    }
    //assert(loop != -1);
    //cerr << loop << endl;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll g = 0;
    for(ll i = 0; i < N; i++) {
        g ^= f(a[i], 0, loop);
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 3; j++) {
            ll nowg = g ^ f(a[i], 0, loop);
            nowg ^= f(a[i] - x[j], j, loop);
            if(nowg == 0) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    for(int i = 0; i < 3; i++) {
        grundy[i].resize(MAX * 2 + 1);
    }
    while(T--) {
        solve();
    }
    return 0;
}