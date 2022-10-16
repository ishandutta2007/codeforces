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
ll memax[5005];
ll memin[5005];
ll clonemax[5005];
ll clonemin[5005];
ll N;
ll t[5005];
ll x[5005];
bool canclear[5005][5005];
ll maxi[5005], mini[5005];
ll nxtmaxi[5005], nxtmini[5005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i <= N; i++) {
        maxi[i] = -INF;
        mini[i] = INF;
        nxtmaxi[i] = -INF;
        nxtmini[i] = INF;
    }
    maxi[0] = 0;
    mini[0] = 0;
    sort(v.begin(), v.end());
    t[0] = 0;
    x[0] = 0;
    for(int i = 0; i < N; i++) {
        t[i+1] = v[i].first;
        x[i+1] = v[i].second;
    }
    for(int i = 0; i <= N; i++) {
        canclear[i][i] = true;
        for(int j = i + 1; j <= N; j++) {
            canclear[i][j] = canclear[i][j-1] & (t[j] - t[j-1] >= abs(x[j] - x[j-1]));
        }
    }
    for(int i = 0; i < N; i++) {
        ll dt = t[i+1] - t[i];
        if(maxi[i] + dt >= x[i+1] and mini[i] - dt <= x[i+1]) {
            ll needt = 0;
            if(maxi[i] <= x[i+1]) needt = x[i+1] - maxi[i];
            if(mini[i] >= x[i+1]) needt = mini[i] - x[i+1];
            ll restt = dt - needt;
            chmax(maxi[i+1], x[i+1] + restt);
            chmin(mini[i+1], x[i+1] - restt);
        }
        if(i + 2 <= N) {
            dt = t[i+2] - t[i];
            if(nxtmaxi[i] + dt >= x[i+2] and nxtmini[i] - dt <= x[i+2]) {
                ll needt = 0;
                if(nxtmaxi[i] <= x[i+2]) needt = x[i+2] - nxtmaxi[i];
                if(nxtmini[i] >= x[i+2]) needt = nxtmini[i] - x[i+2];
                chmax(needt, t[i+1] - t[i]);
                ll restt = dt - needt;
                chmax(maxi[i+2], x[i+2] + restt);
                chmin(mini[i+2], x[i+2] - restt);
            }
        }
        for(ll j = i + 2; j <= N; j++) {
            dt = t[i+1] - t[i];
            ll needt = 0;
            if(maxi[i] <= x[j]) needt = x[j] - maxi[i];
            if(mini[i] >= x[j]) needt = mini[i] - x[j];
            needt += abs(x[j] - x[i+1]);
            if(needt <= dt) {
                if(canclear[i+1][j-1]) {
                    chmax(nxtmaxi[j-1], x[j-1]);
                    chmin(nxtmini[j-1], x[j-1]);
                }
            }
        }
        for(ll j = i + 3; j <= N; j++) {
            dt = t[i+2] - t[i];
            ll needt = 0;
            if(nxtmaxi[i] <= x[j]) needt = x[j] - nxtmaxi[i];
            if(nxtmini[i] >= x[j]) needt = nxtmini[i] - x[j];
            chmax(needt, t[i+1] - t[i]);
            needt += abs(x[j] - x[i+2]);
            if(needt <= dt) {
                if(canclear[i+2][j-1]) {
                    chmax(nxtmaxi[j-1], x[j-1]);
                    chmin(nxtmini[j-1], x[j-1]);
                }
            }
        }
    }
    string ans = "NO";
    if(maxi[N] >= -1e13 and mini[N] <= 1e13) ans = "YES";
    if(nxtmaxi[N-1] >= -1e13 and nxtmini[N-1] <= 1e13) ans = "YES";
    cout << ans << endl;
    return 0;
}