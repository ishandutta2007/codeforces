#include <bits/stdc++.h>
//#include <atcoder/all>
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
const ll mod = 998244353;
ll ans;
ll Last[201000];
void print(vector<ll> v) {
    cerr << "{";
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cerr << ", ";
        cerr << v[i];
    }
    cerr << "}" << endl;
}

void solve() {
    ans = 1;
    ll N, K;
    cin >> N >> K;
    map<ll, ll> mp;
    set<ll> st;
    for(int i = 0; i < N; i++) {
        Last[i] = -1;
        st.insert(i);
        ll a;
        cin >> a;
        mp[a] = i;
    }
    vector<ll> b(K);
    for(int i = 0; i < K; i++) {
        ll a;
        cin >> a;
        b[i] = mp[a];
        Last[b[i]] = i;
    }
    for(int i = 0; i < K; i++) {
        //cerr << "---" << i << " " << b[i] << "---" << endl;
        vector<ll> del;
        auto itr = st.lower_bound(b[i]);
        if(itr == st.end() or *itr != b[i]) {
            ans = 0;
            break;
        }
        if(itr != st.begin()) {
            itr--;
            //cerr << *itr << endl;
            if(Last[*itr] <= i) {
                del.push_back(*itr);
            }
            itr++;
        }
        if(itr != st.end()) {
            itr++;
            if(itr != st.end()) {
                //cerr << *itr << endl;
                if(Last[*itr] <= i) {
                    del.push_back(*itr);
                }
            }
            itr--;
        }
        //print(del);
        if(del.empty()) {
            ans = 0;
            break;
        }
        ans *= del.size();
        ans %= mod;
        st.erase(del[0]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}