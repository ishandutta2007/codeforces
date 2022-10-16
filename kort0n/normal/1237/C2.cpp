#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<i_i, i_i> iiii;
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
int N;
int x[50005], y[50005], z[50005];
map<i_i, vector<i_i> > mp;
map<int, vector<i_i> > mp2;
vector<i_i> ans;
vector<i_i> rest;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i] >> z[i];
        mp[{x[i], y[i]}].push_back({z[i], i});
    }
    for(int i = 1; i <= N; i++) {
        if(mp[{x[i], y[i]}].empty()) continue;
        sort(mp[{x[i], y[i]}].begin(), mp[{x[i], y[i]}].end());
        while(mp[{x[i], y[i]}].size() >= 2) {
            int val = mp[{x[i],y[i]}].back().second;
            ans.push_back({0, 0});
            ans.back().first = val;
            mp[{x[i],y[i]}].pop_back();
            val = mp[{x[i],y[i]}].back().second;
            ans.back().second = val;
            mp[{x[i],y[i]}].pop_back();
        }
        if(mp[{x[i],y[i]}].size()) {
            mp2[x[i]].push_back({y[i], mp[{x[i], y[i]}].back().second});
            mp[{x[i],y[i]}].pop_back();
        }
    }
    for(int i = 1; i <= N; i++) {
        if(mp2[x[i]].empty()) continue;
        sort(mp2[x[i]].begin(), mp2[x[i]].end());
        while(mp2[x[i]].size() >= 2) {
            int val = mp2[x[i]].back().second;
            ans.push_back({0, 0});
            ans.back().first = val;
            mp2[x[i]].pop_back();
            val = mp2[x[i]].back().second;
            ans.back().second = val;
            mp2[x[i]].pop_back();
        }
        if(mp2[x[i]].size()) {
            rest.push_back({x[i], mp2[x[i]].back().second});
            mp2[x[i]].pop_back();
        }
    }
    sort(rest.begin(), rest.end());
    while(rest.size()) {
        int val = rest.back().second;
        ans.push_back({0, 0});
        ans.back().first = val;
        rest.pop_back();
        val = rest.back().second;
        ans.back().second = val;
        rest.pop_back();
    }
    for(auto val : ans) {
        cout << val.first << " " << val.second << endl;
    }
    return 0;
}