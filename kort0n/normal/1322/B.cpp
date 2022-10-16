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
vector<int> A;
int N;
int ans;
ll cnt(vector<int> a, vector<int> b, int digit) {
    //reverse(b.begin(), b.end());
    ll ret = 0;
    for(auto val : b) {
        auto itr = lower_bound(a.begin(), a.end(), (1 << digit) - val);
        ret += distance(itr, a.end());
    }
    return ret;
}

void f(int digit) {
    vector<int> v[2];
    for(int i = 0; i < N; i++) {
        if(A[i] & (1 << digit)) v[0].push_back(A[i] % (1 << digit));
        else v[1].push_back(A[i] % (1 << digit));
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    /*
    cerr << "V[0]:";
    for(auto val : v[0]) cerr << " " << val;
    cerr << endl;
    cerr << "V[1]:";
    for(auto val : v[1]) cerr << " " << val;
    cerr << endl;
    */
    ll ret = 0;
    ret += cnt(v[0], v[0], digit);
    //cerr << digit << " " << ret << endl;
    ret += cnt(v[1], v[1], digit);
    //cerr << digit << " " << ret << endl;
    ret += 2 * ((ll)v[0].size() * (ll)v[1].size() - cnt(v[0], v[1], digit));
    for(int i = 0; i < N; i++) {
        if((A[i]+A[i]) & (1 << digit)) ret--;
    }
    ret /= 2;
    if(ret % 2) ans ^= (1 << digit);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    ll trueans = 0;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int digit = 0; digit <= 24; digit++) {
        f(digit);
    }
    cout << ans << endl;
    return 0;
}