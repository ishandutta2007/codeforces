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
ll N;
vector<l_l> v;
ll a[200100];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        ll b;
        cin >> b;
        v.push_back({a[i], b});
    }
    sort(v.begin(), v.end());
    ll idx = 0;
    ll ans = 0;
    multiset<l_l> st;
    for(ll timer = -1; ; timer++) {
        while(idx < N and v[idx].first == timer) {
            l_l tmp = v[idx];
            swap(tmp.first, tmp.second);
            tmp.first *= -1;
            st.insert(tmp);
            idx++;
        }
        if(st.empty()) {
            if(idx == N) break;
            else timer = v[idx].first - 1;
            continue;
        }
        auto itr = st.begin();
        l_l tmp = *itr;
        ans -= (timer - (tmp.second)) * tmp.first;
        st.erase(itr);
    }
    cout << ans << endl;
    return 0;
}