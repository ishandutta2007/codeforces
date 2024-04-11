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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
vector<i_i> ans;
int N;
int d[1000000], s[1000000];
queue<int> leaf;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> d[i] >> s[i];
        if(d[i] == 1) leaf.push(i);
    }
    while(!leaf.empty()) {
        int now = leaf.front();
        leaf.pop();
        if(d[now] != 1) continue;
        int to = s[now];
        ans.push_back({now, to});
        s[now] ^= to;
        s[to] ^= now;
        d[now]--;
        d[to]--;
        if(d[to] == 1) leaf.push(to);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}