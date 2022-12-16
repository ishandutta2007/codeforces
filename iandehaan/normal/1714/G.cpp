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

#define MAXN 200'010

int n;
int par[MAXN][20];
ll a[MAXN];
ll b[MAXN];
int depth[MAXN];
vi children[MAXN];

int getPar(int ind, int upamt) {
    if (upamt == 0) return ind;
    if (upamt > depth[ind]) return -2;

    int powtwo = 1;
    int index = 0;
    while (powtwo <= upamt) {
        powtwo *= 2;
        index++;
    }
    powtwo /= 2;
    index--;

    if (par[ind][index] == -1) {
        par[ind][index] = par[getPar(ind, powtwo/2)][index-1];
    }
    return getPar(par[ind][index], upamt-powtwo);
}

void dfs(int curr) {
    for (int nxt : children[curr]) {
        depth[nxt] = depth[curr]+1;
        a[nxt] += a[curr];
        b[nxt] += b[curr];
        dfs(nxt);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, 0, n) {
            depth[i] = -1;
            children[i].clear();
            rep(j, 0, 20) {
                par[i][j] = -1;
                depth[i] = -1;
            }
        }
        par[0][0] = -2;
        rep(i, 1, n) {
            cin >> par[i][0] >> a[i] >> b[i];
            par[i][0]--;
            children[par[i][0]].pb(i);
        }
        a[0] = 0;
        b[0] = 0;

        depth[0] = 0;
        dfs(0);

        rep(i, 1, n) {
            int lo = -1;
            int hi = depth[i]+1;
            while (hi-lo > 1) {
                int mid = (lo+hi) / 2;
                int mypar = getPar(i, mid);
                if (mypar == -2) {
                    hi = mid;
                    continue;
                }

                //cout << "myout " << i << ' ' << mypar << ' ' << b[mypar] << ' ' << a[i] << endl;

                if (b[mypar] <= a[i]) {
                    // it's good!
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            cout << depth[i]-hi << ' ';
        }
        cout << '\n';
    }
}