#include <bits/stdc++.h>
//#include <atcoder/all>
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

const long long INF = 1000000000000000001;
//const ll mod = 1000000007;
ll mul(ll a, ll b) {
    if(a == 0 or b == 0) return 0;
    if(INF / a > b) return INF;
    return a * b;
}

ll combination[40000][5];

ll f(ll n, ll c) {
    if(n == 0) return 1;
    ll ret = 0;
    for(ll i = 0; i <= c; i++) {
        ret += combination[n-1][i];
        chmin(ret, INF);
    }
    return ret;
}
vector<l_l> rev;
ll N, C, Q;
vector<ll> p;
vector<ll> v[5];
vector<l_l> A[30100][5];

vector<l_l> h(ll idx, ll c) {
    vector<l_l> a;
    for(int i = 0; i <= c; i++) {
        if(i + idx >= N) break;
        a.emplace_back(i, f(N - idx - 1 - i, c - i));
    }
    sort(a.begin(), a.end(), [&](l_l q, l_l w) {
        return p[idx+q.first] < p[idx+w.first];
    });
    //cerr << "h: " << idx << " "<< c << endl;
    for(auto tmp : a) {
        //cerr << "{" << tmp.first << ", " << tmp.second << "} ";
    }
    //cerr << endl;
    return a;
}

void g(ll idx, ll c, ll num) {
    //cerr << "g: " << idx << " " << c << " " << num << endl;
    if(v[c][N] - v[c][idx] == num) return;
    ll ok = idx - 1;
    ll ng = N - 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        vector<l_l> a = A[mid][c];
        ll val = v[c][mid] - v[c][idx];
        if(val > num) {
            ng = mid;
            continue;
        }
        for(auto tmp : a) {
            if(tmp.first == 0) {
                if(val <= num and num < val + tmp.second) ok = mid;
                else ng = mid;
            } else {
                val += tmp.second;
            }
        }
    }
    //cerr << ok << endl;
    auto a = A[ok+1][c];
    ll val = 0;
    if(ok >= 0) val = v[c][ok+1] - v[c][idx];
    //cerr << val << endl;
    for(auto tmp : a) {
        if(val <= num and num < val + tmp.second) {
            assert(tmp.first != 0);
            rev.push_back({ok+1, tmp.first});
            g(ok+1 + tmp.first + 1, c - tmp.first, num - val);
            return;
        } else {
            val += tmp.second;
        }
    }
    assert(0);
}

void solve() {
    cin >> N >> C >> Q;
    p.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= C; j++) {
            A[i][j] = h(i, j);
        }
    }
    for(int c = 0; c <= 4; c++) {
        v[c].clear();
        v[c].push_back(0);
        //cerr << "---------" << c << "--------" << endl;
        //cerr << "0 ";
        for(int i = 0; i < N; i++) {
            ll val = 0;
            if(i >= 1) val = v[c].back();
            for(int j = 1; j <= c; j++) {
                if(i + j >= N) continue;
                if(p[i+j] >= p[i]) continue;
                val += f(N - i - j - 1, c - j);
            }
            v[c].push_back(val);
            //cerr << val << " ";
        }
        //cerr << endl;
    }
    for(int q = 0; q < Q; q++) {
        //cerr << "-------------" << q << "------------" << endl;
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(f(N, C) < b + 1) {
            cout << -1 << endl;
            continue;
        }
        rev.clear();
        g(0, C, b);
        //cerr << "---------rev---------" << endl;
        ll ans = p[a];
        assert(rev.size() <= C);
        for(auto tmp : rev) {
            //cerr << tmp.first << ", " << tmp.second << endl;
            if(tmp.first <= a and a < tmp.first + tmp.second + 1) {
                ll idx = (a - tmp.first);
                idx = tmp.second + 1 - idx - 1;
                ans = p[tmp.first + idx];
            }
        }
        cout << ans + 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    combination[0][0] = 1;
    for(int i = 1; i < 4e4; i++) {
        combination[i][0] = 1;
        for(int j = 1; j <= 4; j++) {
            combination[i][j] = combination[i-1][j-1] + combination[i-1][j];
            chmin(combination[i][j], INF);
        }
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}