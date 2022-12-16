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

#define MAXN 500'010

int lower[MAXN];
int b[MAXN];
vi begins[MAXN];
int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        rep(i, 0, n) {
            cin >> b[i];
            begins[i].clear();
        }
        begins[n].clear();

        
        rep(i, 0, n) {
            int ind = i+1;
            int low = (ind / (b[i]+1)) + 1;
            int upper = n;
            if (b[i] != 0) upper = (ind / b[i]);
            lower[i] = low;
            begins[upper].pb(i);
        }

        priority_queue<pii> active;
        for (int val = n; val >= 1; val--) {
            for (int nxt : begins[val]) {
                active.push(mp(lower[nxt], nxt));
            }

            a[active.top().second] = val;
            active.pop();
        }
        rep(i, 0, n) cout << a[i] << ' ';
        cout << '\n';
    }
}