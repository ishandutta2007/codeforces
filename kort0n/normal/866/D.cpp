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
vector<int> p;
ll num[301000];
vector<int> inv[1010000];
ll ans = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    p.resize(N);
    set<int> st;
    for(int i = 0; i < N; i++) {
        st.insert(i);
        cin >> p[i];
        inv[p[i]].push_back(i);
        num[i] = 1;
    }
    for(int val = 0; val <= 1e6; val++) {
        for(auto tmp : inv[val]) {
            st.erase(tmp);
        }
        for(auto now : inv[val]) {
            while(num[now]) {
                num[now]--;
                auto itr = st.lower_bound(now + 1);
                if(itr == st.end()) continue;
                ans += p[*itr];
                ans -= p[now];
                num[*itr]++;
                st.erase(itr);
            }
        }
    }
    cout << ans << endl;
    return 0;
}