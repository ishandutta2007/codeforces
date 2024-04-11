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
ll num[105000];
ll num2[105000];
vector<ll> idx[105000];
ll num3[105000];
ll N, X, Y;
vector<ll> check(vector<ll> a, vector<ll> b, ll X, ll Y) {
    for(int i = 0; i < N; i++) {
        assert(0 <= a[i] and a[i] <= N);
    }
    map<ll, ll> numa, numb;
    ll nowY = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] == b[i]) continue;
        numa[a[i]]++;
        numb[b[i]]++;
    }
    for(int i = 0; i <= N; i++) {
        chmin(numa[i], numb[i]);
    }
    vector<ll> ret;
    for(int i = 0; i < N; i++) {
        if(a[i] == b[i]) continue;
        if(numa[a[i]] == 0) continue;
        ret.push_back(i);
        numa[a[i]]--;
    }
    return ret;
}

void solve() {
    cin >> N >> X >> Y;
    for(int i = 0; i <= N + 1; i++) {
        idx[i].clear();
        num[i] = 0;
        num2[i] = 0;
        num3[i] = 0;
    }
    vector<ll> b(N);
    vector<ll> ans(N, -1);
    ll unused = -1;
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
        num[b[i]]++;
        idx[b[i]].push_back(i);
    }
    set<l_l> st;
    for(int i = 0; i <= N; i++) {
        if(num[i] == 0) {
            unused = i;
            continue;
        }
        st.insert({num[i], i});
    }
    for(int x = 0; x < X; x++) {
        auto itr = st.end();
        itr--;
        auto tmp = *itr;
        itr = st.erase(itr);
        int pos = idx[tmp.second].back();
        idx[tmp.second].pop_back();
        ans[pos] = tmp.second;
        tmp.first--;
        if(tmp.first != 0) st.insert(tmp);
    }
    ll unusednum = N - Y;
    vector<l_l> v;
    /*
    for(int y = 0; y < unusednum; y++) {
        assert(st.size());
        auto itr = st.end();
        itr--;
        auto tmp = *itr;
        itr = st.erase(itr);
        int pos = idx[tmp.second].back();
        idx[tmp.second].pop_back();
        v.push_back({unused, pos});
        tmp.first--;
        if(tmp.first != 0) st.insert(tmp);
    }
    */
    for(int i = 0; i <= N + 1; i++) {
        while(idx[i].size()) {
            i_i tmp = {i, idx[i].back()};
            idx[i].pop_back();
            v.push_back(tmp);
        }
    }
    /*
    for(int y = 0; y < Y - X; y++) {
        assert(st.size());
        auto itr = st.begin();
        auto tmp = *itr;
        st.erase(itr);
        num2[tmp.second]++;
        tmp.first--;
        int pos = idx[tmp.second].back();
        idx[tmp.second].pop_back();
        v.push_back({tmp.second, pos});
        if(tmp.first != 0) st.insert(tmp);
    }
    for(int i = 0; i <= N + 1; i++) {
        while(idx[i].size()) {
            i_i tmp = {unused, idx[i].back()};
            idx[i].pop_back();
            v.push_back(tmp);
        }
    }
    */
    sort(v.begin(), v.end());
    int delta = v.size() / 2;
    /*
    for(int i = 0; i < N; i++) cerr << ans[i] << " ";
    cerr << endl;
    */
    for(int i = 0; i < v.size(); i++) {
        int j = (i + delta) % v.size();
        ans[v[i].second] = v[j].first;
        if(v[i].first == v[j].first) ans[v[i].second] = unused;
    }
    /*
    for(auto tmp : v) cerr << tmp.first << " " << tmp.second << endl;
    for(int i = 0; i < N; i++) cerr << ans[i] << " ";
    cerr << endl;
    */
    /*
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
    for(int i = 0; i <= N; i++) cout << num2[i] << " ";
    cout << endl;
    */
    auto ret = check(ans, b, X, Y);
    ll deltaY = Y - X;
    if(deltaY > ret.size()) {
        cout << "NO" << endl;
        return;
    }
    for(int i = deltaY; i < ret.size(); i++) {
        ans[ret[i]] = unused;
    }
    cout << "YES" << endl;
    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    check(ans, b, X, Y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}