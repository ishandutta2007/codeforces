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

#define EPS (1e-16)
#define INF (1e9)
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;
long double x[3000], y[3000];
ll ans;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    for(ll i = 0; i < N; i++) {
        ll nownum = (N-1)*(N-2)*(N-3)/6;
        //cerr << x[i] << " " << y[i] << endl;
        vector<long double> v;
        for(ll j = 0; j < N; j++) {
            if(i == j) continue;
            v.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            v.push_back(atan2(y[j] - y[i], x[j] - x[i]) + 2 * PI);
        }
        sort(v.begin(), v.end());
        //for(auto val : v) cerr << val << " ";
        //cerr << endl;
        for(ll k = 0; k < N - 1; k++) {
            long double now = v[k];
            auto itr = lower_bound(v.begin(), v.end(), now + PI);
            ll num = distance(v.begin(), itr) - k - 1;
            //cerr << num << endl;
            nownum -= (num - 1) * num / 2;
        }
        //ans += nownum;
        ans += nownum * (N - 4) / 2;
        //cerr << "NOW:" << nownum << endl;
    }
    cout << ans << endl;
    return 0;
}