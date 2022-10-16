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
int n, k;
int a[200500];
vector<int> st;

int f(int border) {
    st.clear();
    for(int i = 1; i <= n; i++) {
        st.push_back(a[i] - border - 1);
        st.push_back(a[i] - border);
        st.push_back(a[i] + border);
        st.push_back(a[i] + border + 1);
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    int SIZE = st.size();
    vector<int> v(SIZE);
    for(int i = 1; i <= n; i++) {
        auto itr = lower_bound(st.begin(), st.end(), a[i] - border);
        v[distance(st.begin(), itr)]++;
        itr = lower_bound(st.begin(), st.end(), a[i] + border + 1);
        v[distance(st.begin(), itr)]--;
    }
    for(int i = 1; i < v.size(); i++) v[i] += v[i-1];
    //for(int i = 0; i < v.size(); i++) cerr << v[i] << " ";
    //cerr << endl;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > k) {
            auto itr = st.begin();
            while(i--) itr++;
            return *itr;
        }
    }
    return -1e9;
}

void solve() {
    cin >> n >> k;
    for(int  i = 1; i <= n; i++) cin >> a[i];
    int ok = 1e9;
    int ng = -1;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        int ret = f(mid);
        //cerr << n << " " << k << " " << mid << " " << ret << endl;
        if(ret == -1e9) ng = mid;
        else ok = mid;
    }
    cout << f(ok) << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    //f(10);
    return 0;
}