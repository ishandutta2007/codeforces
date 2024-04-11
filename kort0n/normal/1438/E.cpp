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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
vector<ll> a;
ll ans = 0;
ll sz[205000];
ll nxt[205000][40];
void f() {
    vector<ll> sum(N + 1);
    for(int i = 0; i < N; i++) {
        sz[i] = 0;
        sum[i+1] = sum[i] + a[i];
        ll copy = a[i];
        while(copy) {
            sz[i]++;
            copy /= 2;
        }
    }
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j <= N; j++) {
            nxt[j][i] = INF;
        }
    }
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j <= 35; j++) {
            nxt[i][j] = nxt[i+1][j];
        }
        for(int j = 0; j <= sz[i]; j++) {
            nxt[i][j] = i;
        }
    }
    /*
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= 5; j++) {
            cerr << nxt[i][j] << " ";
        }
        cerr << endl;
    }
    */
    stack<ll> sta;
    for(ll i = N - 1; i >= 0; i--) {
        while(sta.size()) {
            ll idx = sta.top();
            if(a[i] >= a[idx]) sta.pop();
            else break;
        }
        if(sta.empty()) {
            sta.push(i);
            continue;
        }
        //cerr << i << " " << a[i] << " " << sta.top() << " " << a[sta.top()] << endl;
        ll nowidx = sta.top();
        bool First = true;
        while(true) {
            if((a[i] ^ a[nowidx]) == (sum[nowidx] - sum[i+1]) and nowidx >= i + 2) {
                ans++;
                //cerr << i << " " << nowidx << endl;
            }
            ll SZ = sz[nowidx];
            if(!First) {
                SZ++;
            }
            ll newidx = nxt[nowidx+1][SZ];
            if(newidx == INF) break;
            nowidx = newidx;
            if(First and SZ == sz[nowidx]) {
                First = false;
            } else {
                First = true;
            }
        }
        sta.push(i);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    f();
    reverse(a.begin(), a.end());
    f();
    cout << ans << endl;
    return 0;
}