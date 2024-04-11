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
ll N, K;
vector<ll> v[3005];
vector<ll> w;
vector<vector<ll>> ans;
ll Total = 0;
ll num = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    string S;
    cin >> S;
    int MTime = 0;
    for(int t = 1; t <= N; t++) {
        for(int i = 0; i + 1 < N; i++) {
            if(S[i] == 'R' and S[i+1] == 'L') {
                swap(S[i], S[i+1]);
                v[t].push_back(i + 1);
                Total++;
                i++;
            }
        }
        for(int i = 0; i < v[t].size(); i++) {
            if(i == 0) {
                w.push_back(-v[t][i]);
            } else {
                w.push_back(v[t][i]);
            }
        }
        if(v[t].size()) MTime = t;
    }
    cerr << MTime << " " << Total << endl;
    if(K < MTime or K > Total) {
        cout << -1 << endl;
        return 0;
    }
    ans.push_back({abs(w[0])});
    for(int i = 1; i < w.size(); i++) {
        if(w[i] < 0) {
            ans.push_back({});
            ans.back().push_back(-w[i]);
            continue;
        }
        if(Total - i + ans.size() == K) {
            ans.push_back({});
        }
        ans.back().push_back(w[i]);
    }
    for(auto u : ans) {
        cout << u.size();
        for(auto val : u) {
            cout << " " << val;
        }
        cout << endl;
    }
    return 0;
}