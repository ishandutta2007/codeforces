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
ll A[5005];
ll ans;
ll nxt[5005];

void solve() {
    ans = 0;
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        nxt[i] = i + 1;
    }
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) {
        if(A[i] > N - i) {
            ll d = A[i] - (N - i);
            A[i] -= d;
            ans += d;
        }
        if(A[i] == 1) continue;
        while(A[i] >= 2) {
            ans++;
            ll now = i;
            while(now < N) {
                if(A[now] == 1) {
                    while(nxt[now] < N and A[nxt[now]] == 1) {
                        nxt[now]++;
                    }
                    now = nxt[now];
                    continue;
                }
                ll to = now + A[now];
                if(A[now] >= 2) A[now]--;
                now = to;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}