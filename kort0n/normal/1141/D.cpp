#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
string L, R;
map<char, vector<int> > mp;
vector<l_l> ans;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> L >> R;
    L = "#" + L;
    R = "#" + R;
    for(int i = 1; i <= n; i++) mp[R[i]].push_back(i);
    for(int i = 1; i <= n; i++) {
        if(L[i] == '?') continue;
        char now = L[i];
        if(!mp[now].empty()) {
            //cerr << i << " " << now << endl;
            int P = mp[now].back();
            ans.push_back({i, P});
            mp[now].pop_back();
            continue;
        }
        if(!mp['?'].empty()) {
            int P = mp['?'].back();
            ans.push_back({i, P});
            mp['?'].pop_back();
            continue;
        }
    }
    //cerr << "A" << endl;
    set<int> rest;
    for(char moji = 'a'; moji <= 'z'; moji++) {
        //cerr << moji << endl;
        //cerr << mp[moji].size() << endl;
        for(int i = 0; i < mp[moji].size(); i++) rest.insert(mp[moji][i]);
    }
    for(int i = 0; i < mp['?'].size(); i++) rest.insert(mp['?'][i]);
    for(int i = 1; i <= n; i++) {
        if(L[i] != '?') continue;
        if(rest.empty()) continue;
        auto itr = rest.begin();
        ans.push_back({i, *itr});
        rest.erase(itr);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}