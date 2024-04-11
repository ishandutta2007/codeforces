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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll a[25][25];
ll N;
const int LOCAL = 0;
ll K;
vector<l_l> ans;
vector<l_l> localans;
ll dh[2] = {1, 0};
ll dw[2] = {0, 1};
void solve() {
    ans.clear();
    if(LOCAL) {
        //localans.clear();
    } else {
        cin >> K;
    }
    ll h = 0;
    ll w = 0;
    ans.push_back({h, w});
    for(int i = 0; i < 2 * (N - 1); i++) {
        for(int k = 0; k < 2; k++) {
            ll nowh = h + dh[k];
            ll noww = w + dw[k];
            if(nowh >= N) continue;
            if(noww >= N) continue;
            ll tmp = K & (1LL << i);
            if(tmp ^ a[nowh][noww]) continue;
            ans.push_back({nowh, noww});
            h = nowh;
            w = noww;
            break;
        }
    }
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i < 2 * N - 1; i++) {
        for(int h = 0; h < N; h++) {
            int w = i - h;
            if(w < 0) continue;
            if(w >= N) continue;
            a[h][w] = (1LL << (i-1)) * (h % 2);
            assert(a[h][w] <= 1e16);
        }
    }
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            if(w != 0) cout << " ";
            cout << a[h][w];
        }
        cout << endl;
    }
    int Q;
    cin >> Q;
    while(Q--) solve();
    return 0;
}