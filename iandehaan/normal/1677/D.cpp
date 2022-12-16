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

#define MAXN 1'000'010

int a[MAXN];
bool forced[MAXN];
int cap[MAXN];
constexpr ll mod = 998'244'353;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        rep(i, 0, n) cin >> a[i];

        rep(i, 0, n) {
            cap[i] = i;
            forced[i] = false;
        }

        bool poss = true;

        rep(i, 0, n) {
            if (a[i] == -1) {
                // can do anything?
                continue;
            }
            if (a[i] == 0) {
                int newind = i+ k;
                if (newind < n) {
                    cap[newind] = min(cap[newind], k);
                }
                continue;
            }
            int newind = i + k;
            if (newind >= n) {
                poss = false;
                break;
            }
            forced[newind] = true;
            int forcedval = a[i] + k;
            if (forcedval > cap[newind]) {
                poss = false;
                break;
            }
        }
        if (!poss) {
            cout << 0 << endl;
            continue;
        }

        ll out = 1;
        for (int i = 0; i < n; i++) {
            //cout << forced[i] << ' ' << cap[i] << endl;
            if (!forced[i]) {
                out *= (cap[i]+1);
                out %= mod;
            }
        }
        cout << out << endl;
    }
}