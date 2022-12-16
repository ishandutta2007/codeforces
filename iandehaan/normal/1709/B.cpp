#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 100'010

ll a[MAXN];
ll pre[MAXN];
ll post[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    rep(i, 0, n) cin >> a[i];

    pre[0] = 0;
    rep(i, 1, n) {
        pre[i] = pre[i-1];
        if (a[i] < a[i-1]) {
            pre[i] += a[i-1]-a[i];
        }
    }
    post[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        post[i] = post[i+1];
        if (a[i] < a[i+1]) {
            post[i] += a[i+1]-a[i];
        }
    }

    while (m--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        if (s < t) {
            ll out = pre[t] - pre[s];
            cout << out << '\n';
        } else {
            ll out = post[t] - post[s];
            cout << out << '\n';
        }
    }
}