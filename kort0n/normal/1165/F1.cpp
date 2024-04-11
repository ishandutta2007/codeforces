#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n, m;
ll k[200050];
ll d[200050], t[200050];
ll lastday[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> k[i];
    for(int i = 1; i <= m; i++) cin >> d[i] >> t[i];
    ll ok = 400000;
    ll ng = 0;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        for(int i = 1; i <= n; i++) lastday[i] = -1;
        for(int i = 1; i <= m; i++) {
            if(d[i] <= mid) {
                lastday[t[i]] = max(lastday[t[i]], d[i]);
            }
        }
        set<l_l> st;
        ll lastneed = 0;
        for(ll i = 1; i <= n; i++) {
            if(lastday[i] != -1) {
                st.insert({lastday[i], i});
                //cerr << i << " " << lastday[i] << endl;
            } else {
                lastneed += 2 * k[i];
            }
        }
        ll nowday = 0;
        ll nowmoney = 0;
        for(auto itr = st.begin(); itr != st.end(); itr++) {
            l_l now = *itr;
            //cerr << nowday << " " << nowmoney << " " << now.first << " " << now.second << endl;
            nowmoney += (*itr).first - nowday;
            nowday = (*itr).first;
            ll buy = min(k[now.second], nowmoney);
            nowmoney -= buy;
            lastneed += 2 * (k[now.second] - buy);
        }
        nowmoney += mid - nowday;
        if(nowmoney >= lastneed) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}