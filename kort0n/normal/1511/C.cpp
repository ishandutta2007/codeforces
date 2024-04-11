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
int N, Q;
int pos[60];
int a[301000];
bool called[60];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i = 0; i < 50; i++) {
        pos[i] = -1;
        called[i] = false;
    }
    vector<int> others;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        if(pos[a[i]] == -1) pos[a[i]] = i;
        else {
            others.push_back(i);
        }
    }
    vector<int> v;
    for(int q = 0; q < Q; q++) {
        if(q != 0) cout << " ";
        int t;
        cin >> t;
        t--;
        if(called[t]) {
            auto itr = find(v.begin(), v.end(), t);
            cout << itr - v.begin() + 1;
            v.erase(itr);
            v.insert(v.begin(), t);
        } else {
            ll ans = 0;
            auto itr = lower_bound(others.begin(), others.end(), pos[t]);
            ans += itr - others.begin();
            for(int c = 0; c < 50; c++) {
                if(pos[c] == -1) continue;
                if(t == c) continue;
                if(called[c] or pos[c] < pos[t]) ans++;
            }
            cout << ans + 1;
            called[t] = true;
            v.insert(v.begin(), t);
        }
    }
    cout << endl;
    return 0;
}