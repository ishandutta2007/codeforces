#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll a[1510];
ll sum[1510];
unordered_map<ll, vector<l_l> > mp;
set<ll> appeared;
ll ans = 0;
ll val = -1;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ll now = sum[j] - sum[i - 1];
            appeared.insert(now);
            mp[now].push_back({j, i});
        }
    }
    for(auto itr = appeared.begin(); itr != appeared.end(); itr++) {
        //cerr << endl;
        //cerr << *itr << endl;
        sort(mp[*itr].begin(), mp[*itr].end());
        int pos = 0;
        int now = 0;
        for(int i = 0; i < mp[*itr].size(); i++ ) {
            //cerr << mp[*itr][i].second << " " << mp[*itr][i].first << endl;
            if(mp[*itr][i].second <= pos) continue;
            now++;
            pos = mp[*itr][i].first;
        }
        if(now > val) {
            ans = *itr;
            val = now;
        }
    }
    //cerr << ans << " " << val << endl;
    cout << val << endl;
    int pos = 0;
    int now = 0;
    for(int i = 0; i < mp[ans].size(); i++ ) {
        if(mp[ans][i].second <= pos) continue;
        now++;
        pos = mp[ans][i].first;
        cout << mp[ans][i].second << " " << mp[ans][i].first << endl;
    }
    return 0;
}