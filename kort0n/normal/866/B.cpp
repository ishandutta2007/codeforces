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
vector<l_l> v;
vector<l_l> sum;
ll N, S;
ll num;
ll ssum = 0;
ll base = 0;
ll ans = 0;

ll g(ll num) {
    ll ok = 0;
    ll ng = sum.size();
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(sum[mid].first <= num) ok = mid;
        else ng = mid;
    }
    ll ret = sum[ok].second;
    ll rest = num - sum[ok].first;
    if(rest) {
        ret += rest * v[ok].first;
    }
    return ret;
}

void f(ll anum) {
    ll bnum = ssum - anum;
    if(anum < 0 or bnum < 0) return;
    if((anum+S-1)/S+(bnum+S-1)/S > (ssum + S - 1) / S) return;
    chmax(ans, base + g(anum));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    num = (N + S - 1) / S;
    for(int i = 0; i < N; i++) {
        ll s, a, b;
        cin >> s >> a >> b;
        ssum += s;
        base += s * a;
        v.push_back({b-a, s});
    }
    sort(v.begin(), v.end(), greater<l_l>());
    sum.resize(N + 1);
    for(int i = 0; i < N; i++) {
        sum[i+1].first = sum[i].first + v[i].second;
        sum[i+1].second = sum[i].second + v[i].first*v[i].second;
    }
    /*
    for(auto tmp : v) {
        cerr << tmp.first << " " << tmp.second << endl;
    }
    for(auto tmp : sum) {
        cerr << tmp.first << " " << tmp.second << endl;
    }
    */
    int idx = 0;
    while(idx < v.size()) {
        if(v[idx].first <= 0) break;
        idx++;
    }
    for(int i = -1e6; i <= 1e6; i++) {
    //for(int i = -10; i <= 10; i++) {
        f(sum[idx].first + i);
    }
    cout << ans << endl;
    return 0;
}