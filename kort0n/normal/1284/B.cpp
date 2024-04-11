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
ll N;
map<ll, ll> Left, Right;
set<ll> st;
ll ans;
ll now;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        ll l;
        cin >> l;
        ll mini = 1e9;
        ll maxi = 0;
        bool ok = true;
        for(int i = 1; i <= l; i++) {
           ll a;
           cin >> a;
           if(a > mini) ok = false;
           chmax(maxi, a);
           chmin(mini, a); 
        }
        if(ok) {
            Left[mini]++;
            Right[maxi]++;
            st.insert(mini);
            st.insert(maxi);
        }
    }
    for(auto val : st) {
        now += Right[val];
        ans += Left[val] * now;
    }
    cout << N * N - ans << endl;
    return 0;
}