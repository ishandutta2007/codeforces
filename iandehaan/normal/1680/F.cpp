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


vector<pii> bridges; 

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	for (auto pa : ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ bridges.pb(mp(at, y)); }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int numbad;
vector<int> adj[MAXN];
int depth[MAXN];
int eid;
int loweststart;
int lowetstartpt;
int isstart[MAXN];
int par[MAXN];
bool isend[MAXN];
int highestend;
int highestendpt;

void dfs1(int curr) {
    int color = depth[curr] % 2;
    for (int nxt : adj[curr]) {
        if (depth[nxt] == -1) {
            par[nxt] = curr;
            depth[nxt] = depth[curr] + 1;
            //cout << curr << ' ' << nxt << endl;
            ed[curr].emplace_back(nxt, eid);
            ed[nxt].emplace_back(curr, eid++);
            dfs1(nxt);
        } else {
            int nxtcolor = depth[nxt] % 2;
            if (nxtcolor != color && depth[nxt] < depth[curr]-1) {
                //cout << "back " << curr << ' ' << nxt << endl;
                ed[curr].emplace_back(nxt, eid);
                ed[nxt].emplace_back(curr, eid++);
            } else if (nxtcolor == color && depth[nxt] < depth[curr]) {
                if (loweststart < depth[nxt]) {
                    lowetstartpt = nxt;
                    loweststart = depth[nxt];
                }
                isstart[nxt]++;
                isend[curr] = true;
                if (highestend > depth[curr]) {
                    highestend = depth[curr];
                    highestendpt = curr;
                }
                //highestend = min(highestend, depth[curr]);
                //loweststart = max(loweststart, depth[nxt]);
                //cout << "bad " <<  nxt << ' ' << curr << endl;
                numbad++;
            }
        }
    }
}

bool dfs2succ = true;
pii tocut;
int clr[MAXN];
void dfs2(int curr) {
    //cout << curr << ' ' << clr[curr] << endl;
    for (int nxt : adj[curr]) {
        
        if (curr == tocut.first && nxt == tocut.second) continue;
        if (curr == tocut.second && nxt == tocut.first) continue;
        if (clr[nxt] == clr[curr]) dfs2succ = false;
        if (clr[nxt] != -1) continue;
        clr[nxt] = (clr[curr]+1)%2;
        dfs2(nxt);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        numbad = 0;
        eid = 0;
        loweststart = -1;
        highestend = n;
        dfs2succ = true;
        ed.clear();
        ed.resize(n);
        bridges.clear();
        tocut = mp(-1, -1);
        rep(i, 0, n) {
            isstart[i] = 0;
            adj[i].clear();
            depth[i] = -1;
            isend[i] = false;
            clr[i] = -1;
            
        }
        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        par[0] = -2;
        depth[0] = 0;
        dfs1(0);

        //cout << numbad << endl;

        if (numbad == 0) {
            cout << "YES\n";
            // graph already bipartite
            for (int i = 0; i < n; i++) {
                int color = depth[i] % 2;
                cout << color;
            }
            cout << '\n';
            continue;

        } else if (numbad == 1) {
            cout << "YES\n";
            int baddepth = depth[lowetstartpt];
            if (baddepth % 2 == 1) {
                for (int i = 0; i < n; i++) {
                    int color = depth[i] % 2;
                    cout << color;
                }
                cout << '\n';
            } else {
                for (int i = 0; i < n; i++) {
                    int color = (depth[i]+1) % 2;
                    cout << color;
                }
                cout << '\n';
            }
            continue;
        }

        // check if all starts are in one line

        int curr = lowetstartpt;
        int numstartsseen = isstart[curr];
        
        while (curr != 0) {
            //possedges.insert(mp(curr, par[curr]));
            //cout << "allow " << curr << ' ' << par[curr] << endl;
            curr = par[curr];
            numstartsseen += isstart[curr];
        }

        // adding too many edges...
        set<pii> possedges;
        curr = highestendpt;
        while (curr != 0) {
            possedges.insert(mp(curr, par[curr]));
            curr = par[curr];
        }
        //cout << numstartsseen << ' ' << numbad << endl;
        if (numstartsseen != numbad) {
            //cout << "this no" << endl;
            cout << "NO" << endl;
            continue;
        }

        // need to remove an edge
        bicomps([&](const vi& edgelist) {

        });
        // bridges now contains all bridges

        

        //cout << loweststart << ' ' << highestend << endl;

        for (pii &x : bridges) {
            if (abs(depth[x.first]-depth[x.second]) > 1) continue;
            if (possedges.count(x) == 0 && possedges.count(mp(x.second, x.first)) == 0) continue;
            int mydepth = min(depth[x.first], depth[x.second]);
            if (mydepth >= loweststart && mydepth < highestend) {
                if (tocut.first == -1 || mydepth < depth[tocut.first]) {
                if (depth[x.first] < depth[x.second]) tocut = mp(x.first, x.second);
                else tocut = mp(x.second, x.first);
                }
            }
        }
        if (tocut.first == -1) {
            cout << "NO" << endl;
            continue;
        }

        // cut at x

        //cout << "cutting at " << tocut.first << ' ' << tocut.second << endl;

        clr[tocut.first] = 1;
        dfs2(tocut.first);
        clr[tocut.second] = 1;
        dfs2(tocut.second);

        if (dfs2succ) {
        cout << "YES\n";
        rep(i, 0, n) cout << clr[i];
        cout << '\n';
        }
        else cout << "NO\n";


    }
}