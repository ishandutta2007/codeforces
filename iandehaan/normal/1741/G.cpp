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

#define MAXN 10'010

bool poss[MAXN][(1 << 6)];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        vector<int> spath[n];
        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int dists[n];
        rep(i, 0, n) dists[i] = 1e8;
        dists[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (int nxt : adj[top]) {
                if (dists[nxt] >= dists[top]+1) {
                    spath[top].pb(nxt);
                    //cout << "spath " << top+1 << ' ' << nxt+1 << endl;
                    if (dists[nxt] > dists[top]+1) {
                        dists[nxt] = dists[top]+1;
                        q.push(nxt);
                    }
                }
            }
        }


        int numfriends;
        cin >> numfriends;
        int houses[numfriends];
        rep(i, 0, numfriends) {
            cin >> houses[i];
            houses[i]--;
        }

        int k;
        cin >> k;
        int nocars[k];
        rep(i, 0, k) {
            cin >> nocars[i];
            nocars[i]--;
        }

        rep(i, 0, n) rep(mask, 0, (1 << k)) poss[i][mask] = false;

        bool seen[n];
        rep(i, 0, n) seen[i] = false;
        seen[0] = true;

        poss[0][0] = true;
        q.push(0);
        while (!q.empty()) {
            int top = q.front(); q.pop();
            int nocarmask = 0;;
            rep(i, 0, k) if (houses[nocars[i]] == top) nocarmask |= (1 << i);

            rep(mask, 0, (1 << k)) {
                if (poss[top][mask]) poss[top][mask | nocarmask] = true;
            }

            for (int nxt : spath[top]) {
                rep(mask, 0, (1 << k)) {
                    if (poss[top][mask]) poss[nxt][mask] = true;
                }
                if (!seen[nxt]) {
                    seen[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        bool rp[(1 << k)];
        rep(mask, 0, (1 << k)) rp[mask] = false;
        rp[0] = true;

        rep(i, 0, numfriends) {
            int position = houses[i];
            bool hascar = true;
            rep(j, 0, k) if (nocars[j] == i) hascar = false;
            if (!hascar) continue;

            //cout << "has car " << i << ' ' << position << endl;

            bool newp[(1 << k)];
            rep(mask, 0, (1 << k)) {
                newp[mask] = rp[mask]; 
            }

            rep(mask, 0, (1 << k)) {
                if (!poss[position][mask]) continue;
                //cout << "possible mask " << mask << endl;
                rep(mask2, 0, (1 << k)) {
                    if (rp[mask2]) newp[mask | mask2] = true;
                }
            }


            rep(mask, 0, (1 << k)) {
                rp[mask] = newp[mask]; 
            }
        }

        int out = k;
        rep(mask, 0, (1 << k)) {
            if (!rp[mask]) continue;
            int nbits = 0;
            rep(i, 0, k) if (mask & (1 << i)) nbits++;
            out = min(out, k-nbits);
        }
        cout << out << '\n';
    }
}