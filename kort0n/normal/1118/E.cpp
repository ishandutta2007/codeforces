#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
int n, k;
vector<i_i> ans;
int main() {
    //cout.precision(10);
    cin >> n >> k;
    for(int delta = 1; delta < k; delta++) {
        if(ans.size() >= n) break;
        for(int man = 1; man + delta <= k; man++) {
            ans.push_back({man, man + delta});
        }
        for(int man = k; man - delta >= 1; man--) {
            ans.push_back({man, man - delta});
        }
    }
    if(ans.size() < n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}