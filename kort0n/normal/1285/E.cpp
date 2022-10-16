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
ll N;
ll l[205000], r[205000];
ll num[1000000];
ll idxsum[1000000];
ll Dec[205000];

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        Dec[i] = 0;
    }
    for(int i = 0; i <= 4 * N; i++) {
        num[i] = 0;
        idxsum[i] = 0;
    }
    vector<ll> cmp;
    for(int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        r[i]++;
        cmp.push_back(l[i]);
        cmp.push_back(r[i]);
    }
    cmp.push_back(-2e9);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), l[i]);
        l[i] = distance(cmp.begin(), itr);
        itr = lower_bound(cmp.begin(), cmp.end(), r[i]);
        r[i] = distance(cmp.begin(), itr);
        //cerr << i << " " << l[i] << " " << r[i] << endl;
    }
    for(int i = 0; i < N; i++) {
        num[l[i]]++;
        num[r[i]]--;
        idxsum[l[i]] += i;
        idxsum[r[i]] -= i;
    }
    for(int i = 1; i <= 4 * N; i++) {
        num[i] += num[i-1];
        idxsum[i] += idxsum[i-1];
    }
    for(int i = 1; i <= 4 * N; i++) {
        //cerr << i << " " << num[i] << " " << idxsum[i] << endl;
        if(num[i] == 1 and num[i-1] >= 2 and num[i+1] >= 2) {
            //cerr << "ok:" << i << " " << idxsum[i] << endl;
            Dec[idxsum[i]]++;
        }
        if(num[i] == 1 and num[i-1] == 0 and num[i+1] == 0) {
            Dec[idxsum[i]]--;
        }
    }
    ll ansidx = 0;
    for(int i = 0; i < N; i++) {
        //cerr << i << " " << Dec[i] << endl;
    }
    for(int i = 1; i < N; i++) {
        //cerr << i << " " << Dec[i] << endl;
        if(Dec[i] > Dec[ansidx]) ansidx = i;
    }
    //cerr << "ansidx:" << ansidx << endl;
    for(int i = l[ansidx]; i < r[ansidx]; i++) {
        num[i]--;
    }
    ll ans = 0;
    for(int i = 1; i <= 4 * N; i++) {
        //cerr << num[i] << " ";
        if(num[i] == 0 and num[i-1] >= 1) {
            ans++;
        }
    }
    //cerr << endl;
    cout << ans << "\n";
    //cerr << ansidx << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}