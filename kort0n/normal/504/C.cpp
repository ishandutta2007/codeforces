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
ll a[105000];
set<int> st;
map<int, int> mp;
void Plus(int i) {
    mp[i]++;
    if(mp[i] < 0 || mp[i] % 2 == 1) {
        st.insert(i);
    } else {
        auto itr = st.lower_bound(i);
        if(itr != st.end() && *itr == i) {
            st.erase(itr);
        }
    }
}

void Minus(int i) {
    mp[i]--;
    if(mp[i] < 0 || mp[i] % 2 == 1) {
        st.insert(i);
    } else {
        auto itr = st.lower_bound(i);
        if(itr != st.end() && *itr == i) {
            st.erase(itr);
        }
    }
}

void Plus2(int i) {
    Plus(i);
    Plus(i);
}

ll ans[2];
int mid = -1;

bool ok(int index) {
    if(st.empty()) return true;
    if(mid != -1 && index >= mid) {
        if(st.size() == 1) {
            auto itr = st.begin();
            if(mp[*itr] > 0 && mp[*itr] % 2 == 1) return true;
        }
    }
    return false;
}

void f() {
    int r = 0;
    int l = 1e9;
    for(int i = 1; N-i+1 >= i ; i++) {
        if(a[i] != a[N-i+1]) {
            chmax(r, i);
            chmin(l, i);
        }
    }
    ll factor = l;
    for(int i = l; i < r; i++) {
        Plus(a[i]);
        Minus(a[N-i+1]);
    }
    int boundary = N - l + 1;
    for(int i = r; i <= N; i++) {
        if(i == mid) {
            Plus(a[i]);
        } else if(i <= N / 2) {
            Plus(a[i]);
            Minus(a[N-i+1]);
        } else {
            Plus2(a[i]);
        }
        /*
        cerr << "----" << i << "----" << endl;
        for(auto itr = st.begin(); itr != st.end(); itr++) {
            cerr << *itr << " " << mp[*itr] << endl;
        }
        */
        if(ok(i)) {
            if(i >= boundary) {
                //cerr << "one: " << factor << endl;
                ans[1] += factor;
            } else {
                //cerr << "zerp: " << factor << endl;
                ans[0] += factor;
            }
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    if(N & 1) mid = N / 2 + 1;
    for(int i = 1; i <= N; i++) cin >> a[i];
    int r = 0;
    int l = 1e9;
    for(int i = 1; N-i+1 >= i ; i++) {
        if(a[i] != a[N-i+1]) {
            chmax(r, i);
            chmin(l, i);
        }
    }
    if(r == 0) {
        cout << N * (N - 1) / 2 + N << endl;
        return 0;
    }
    f();
    st.clear();
    mp.clear();
    for(int i = 1; N - i + 1 >= i; i++) swap(a[i], a[N-i+1]);
    f();
    cout << ans[0] + ans[1] / 2 << endl;
    return 0;
}