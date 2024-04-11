#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll n, m;
vector<ll> before[5005];
vector<ll> after[5005];

int main() {
    //cout.precision(10);
    cin >> n>> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if(a < b) after[a].push_back(b);
        else before[a].push_back(b);
    }
    ll loop = 0;
    for(int i = 1; i <= n; i++) {
        sort(after[i].begin(), after[i]. end());
        sort(before[i].begin(), before[i].end());
        for(int j = 0; j < before[i].size(); j++) {
            after[i].push_back(before[i][j]);
        }
        if(loop + 1 < after[i].size()) loop = after[i].size() - 1;
    }
    ll needed[5005];
    for(int i = 1; i <= n; i++) {
        if(after[i].empty()) continue;
        needed[i] = after[i][0] - i;
        if(after[i][0] < i) needed[i] = n + after[i][0] - i;
        //cout << i << " " << needed[i] << endl;
    }
    for(int i = 1; i <= n; i++) {
        ll ans = 0;
        ll dist = -1;
        bool checker = false;
        for(int j = i; ; j++) {
            //cout << i << " " << j << endl;
            if(j > n) j = 1;
            if(j == i) {
                if(checker) break;
                checker = true;
            }
            dist++;
            if(after[j].empty()) continue;
            ll loop = after[j].size() - 1;
            //cout << i << " " << j << " " << loop << " " << dist << endl;
            ans = max(ans, loop * n + dist + needed[j]);
        }
        cout << ans;
        if(i < n) cout << " ";
    }
    cout << endl;
    return 0;
}