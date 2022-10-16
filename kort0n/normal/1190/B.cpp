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
set<ll> st;
map<ll, ll> mp;
ll N;
ll a[105000];

bool canmove() {
    for(int i = 1; i <= N; i++) {
        /*
        cerr << "---" << i << "---" << endl;
        for(auto itr = st.begin(); itr != st.end(); itr++) cerr << *itr << " ";
        cerr << endl;
        */
        if(a[i] == 0) continue;
        if(mp[a[i]] == 1) {
            auto itr = st.lower_bound(a[i]);
            st.erase(itr);
        }
        st.insert(a[i]-1);
        if(st.size() == N) return true;
        if(mp[a[i]-1] == 0) {
            auto itr = st.lower_bound(a[i]-1);
            st.erase(itr);
        }
        st.insert(a[i]);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll sum = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        sum += a[i];
        st.insert(a[i]);
        mp[a[i]]++;
    }
    if(!canmove()) {
        cout << "cslnb" << endl;
        return 0;
    }
    sum -= N * (N - 1) / 2;
    cerr << sum << endl;
    if(sum & 1LL) {
        cout << "sjfnb" << endl;
    } else {
        cout << "cslnb" << endl;
    }
    return 0;
}