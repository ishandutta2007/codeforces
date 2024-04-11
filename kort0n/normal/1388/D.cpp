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
ll N;
ll a[201000], b[201000], c[201000];
vector<ll> children[201000];
deque<ll> ans;
ll ansval = 0;

void dfs(ll now) {
    for(auto to : children[now]) {
        dfs(to);
        c[now] += max(0LL, c[to]);
    }
}

void dfs2(ll now) {
    for(auto to : children[now]) {
        if(c[to] < 0) ans.push_back(to);
        else ans.push_front(to);
        dfs2(to);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        if(b[i] != -1) {
            b[i]--;
            children[b[i]].push_back(i);
        }
    }
    for(int i = 0; i < N; i++) {
        if(b[i] == -1) {
            dfs(i);
            ans.push_back(i);
            dfs2(i);
        }
    }
    for(auto tmp : ans) {
        ansval += a[tmp];
        if(b[tmp] != -1) a[b[tmp]] += a[tmp];
    }
    cout << ansval << endl;
    for(auto tmp : ans) cout << tmp + 1 << " ";
    cout << endl;
    return 0;
}