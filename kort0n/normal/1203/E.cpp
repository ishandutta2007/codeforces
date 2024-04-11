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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    set<int> st;
    for(int i = 0; i < N; i++) {
        for(int j = -1; j <= 1; j++) {
            int now = a[i] + j;
            if(now <= 0) continue;
            auto itr = st.lower_bound(now);
            if(itr != st.end()) continue;
            st.insert(now);
            break;
        }
    }
    cout << st.size() << endl;
    return 0;
}