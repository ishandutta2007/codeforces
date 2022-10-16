#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> train;
    for(int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        train.push_back(in);
    }
    sort(train.begin(), train.end(), greater<int>());
    int ans = 0;
    while(!train.empty()) {
        if(train.back() >= ans + 1) {
            ans++;
        }
        train.pop_back();
    }
    cout << ans << endl;
    return 0;
}