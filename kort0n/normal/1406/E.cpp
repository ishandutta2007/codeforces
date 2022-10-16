#include <bits/stdc++.h>
//#include <atcoder/all>
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

bool IsPrime(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
const ll LOCAL = 0;

vector<ll> P;
ll border = 0;
ll ans = 1;
ll N;

ll trueans;
set<ll> st;

ll ret;
ll T = 0;
void ask(char a, ll x) {
    cout << a << " " << x << endl;
    T++;
    assert(T <= 10000);
    if(LOCAL) {
        if(a == 'C') {
            assert(x == trueans);
            exit(0);
        }
        ll num = 0;
        for(int i = x; i <= N; i += x) {
            if(st.find(i) != st.end()) num++;
            if(a == 'B') st.erase(i);
        }
        st.insert(trueans);
        ret = num;
    } else {
        cin >> ret;
    }
}

void f(ll x) {
    ask('B', x);
    ask('A', x);
    if(ret == 0) return;
    assert(ret == 1);
    ll factor = x;
    while(true) {
        if(factor > N) {
            ans *= factor / x;
            return;
        }
        ask('A', factor);
        if(ret == 0) {
            ans *= factor / x;
            return;
        }
        factor *= x;
    }
}

void g(vector<ll> v) {
    ask('A', 1);
    ll total = ret;
    for(auto tmp : v) {
        ask('B', tmp);
        total -= ret;
    }
    ask('A', 1);
    if(total == ret) return;
    for(auto tmp : v) {
        ask('B', tmp);
        if(ret == 0) continue;
        ans *= tmp;
    }
}

int main() {
    cin >> N;
    if(LOCAL) {
        trueans = rand() % (N - 1) + 1;
        for(int i = 1; i <= N; i++) {
            st.insert(i);
        }
    }
    for(ll i = 2; i <= N; i++) {
        if(!IsPrime(i)) continue;
        P.push_back(i);
        if(i <= 400) border++;
    }
    for(int i = 0; i < border; i++) {
        f(P[i]);
    }
    for(int i = border; i < P.size(); i += 100) {
        vector<ll> v;
        for(int j = i; j < i + 100; j++) {
            if(j < P.size()) v.push_back(P[j]);
        }
        g(v);
    }
    ask('C', ans);
    return 0;
}