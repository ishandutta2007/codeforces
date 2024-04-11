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
ll Prev[10], Next[10];
vector<ll> q;

void g() {
    sort(q.begin(), q.end(), greater<ll>());
    ll sum = 0;
    for(int i = 0; i < q.size(); i++) {
        sum += q[i];
    }
    ll num = q.size();
    for(int i = 0; i < 10; i++) {
        ll newi = i + num;
        ll val = sum;
        if(newi >= 10) {
            newi -= 10;
            val += q[0];
        }
        chmax(Next[newi], Prev[i] + val);
    }
}

void f() {
    for(int i = 0; i < 10; i++) Next[i] = -1e18;
    ll k;
    vector<ll> v[4];
    cin >> k;
    for(ll i = 0; i < k; i++) {
        ll c, d;
        cin >> c >> d;
        v[c].push_back(d);
    }
    for(int i = 1; i <= 3; i++) {
        sort(v[i].begin(), v[i].end(), greater<ll>());
    }
    for(int i = 1; i <= 3; i++) {
        if(v[i].size() >= 1) {
            q.clear();
            q.push_back(v[i][0]);
            g();
        }
    }
    if(v[2].size() >= 1 && v[1].size() >= 1) {
        q.clear();
        q.push_back(v[2][0]);
        q.push_back(v[1][0]);
        g();
    }
    if(v[1].size() >= 2) {
        q.clear();
        q.push_back(v[1][0]);
        q.push_back(v[1][1]);
        g();
    }
    if(v[1].size() >= 3) {
        q.clear();
        q.push_back(v[1][0]);
        q.push_back(v[1][1]);
        q.push_back(v[1][2]);
        g();
    }
    q.clear();
    g();
    swap(Prev, Next);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i < 10; i++) {
        Prev[i] = -1e18;
    }
    while(n--) f();
    ll ans = 0;
    for(ll i = 0; i < 10; i++) {
        chmax(ans, Prev[i]);
    }
    cout << ans << endl;
    return 0;
}