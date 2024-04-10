//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
const int S = 205, T = 205;
vi eg[maxn], ord;
int bst[T][maxn]; // best to reach with energy

int fl[maxn];

int tp[maxn];
int h[maxn];
void dfs1(int a, int fa) {
	ord.pb(a);
    h[a] = maxn;
    if (tp[a]) h[a] = 0; 
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs1(v, a);
        chkmin(h[a], h[v] + 1);
    }
}
void dfs2(int a, int fa) {
    for (auto v : eg[a]) {
        if (v == fa) continue;
        chkmin(h[v], h[a] + 1);
        dfs2(v, a);
    }
}

int nd[maxn];

vi leg[maxn], seg[maxn], geg[maxn];

void dfs4(int a, int fa) {
    for (auto v : geg[a]) chkmin(nd[v], max(0, nd[a] - 1));
    for (auto v : seg[a]) chkmin(nd[v], nd[a] + 1);
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs4(v, a);
    }
}
int res[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &tp[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        eg[u].pb(v), eg[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        for (auto v : eg[i])
            if (h[v] < h[i]) leg[i].pb(v);
            else if (h[v] == h[i]) seg[i].pb(v);
            else geg[i].pb(v);
    vi cur;
    vector<pi> s;
    for (int i = 1; i <= n; i++)
        s.pb(mp(h[i], i));
    for (int i = 1; i <= n; i++)
        if (seg[i].size()) fl[i] = 1;
    sort(s.begin(), s.end());
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < T; j++)
            bst[j][i] = maxn;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && s[j].fi == s[i].fi) j++;
        vi nid(j - i);
        for (int k = i; k < j; k++)
            nid[k - i] = s[k].se;
    
        // compute bst
        for (auto v : nid)
            if (fl[v]) 
                for (int j = 0; j < T; j++)
                    bst[j][v] = h[v];
        static int tmpa[maxn*2][2],tmpb[maxn*2][2];
        int tota=0,totb=0;
        for (auto v:nid) for (auto e:leg[v]) {
        	tmpa[tota][0]=v,tmpa[tota][1]=e;
        	tota++;
        }

        for (auto v:nid) for (auto e:seg[v]) {
        	tmpb[totb][0]=v,tmpb[totb][1]=e;
        	totb++;
        }

        for (int l = 0; l < T; l++) {
            int nx = min(T - 1, l + 1);
            for (int j=0;j<tota;j++) {
                chkmin(bst[l][tmpa[j][0]], bst[nx][tmpa[j][1]]);
            }
                        
            if (l) {
	            for (int j=0;j<totb;j++) {
	                chkmin(bst[l][tmpb[j][0]], bst[l-1][tmpb[j][1]]);
	            }
            }
        }
        i = j;
    }
    auto rord = ord;
    reverse(rord.begin(), rord.end());
    int t1 = 0;
    static int pl[maxn], pr[maxn], fleg[2*maxn], ql[maxn], qr[maxn], fseg[2*maxn],
    	rl[maxn],rr[maxn],fgeg[2*maxn];
    assert(rord.size()==n);
    for (int i=0;i<n;i++) {
    	int a=rord[i];
    	pl[a] = t1;
    	for (auto v:leg[a]) fleg[t1++]=v;
    	pr[a] = t1;
    }
    t1=0;
    for (int i=0;i<n;i++) {
    	int a=rord[i];
    	ql[a] = t1;
    	for (auto v:seg[a]) fseg[t1++]=v;
    	qr[a] = t1;
    }
    t1=0;
    for (int i=0;i<n;i++) {
    	int a=rord[i];
    	rl[a] = t1;
    	for (auto v:geg[a]) fgeg[t1++]=v;
    	rr[a] = t1;
    }
    for (int i = 1; i <= n; i++)
        res[i] = bst[0][i];
    for (int j = 0; j < S; j++) {
        for (int i = 1; i <= n; i++) {
            nd[i] = maxn;
            if (fl[i] && h[i] <= j) nd[i] = 0;
        }
        for (int i=0;i<n;i++) {
        	int a=rord[i];
        	for (int j = pl[a]; j<pr[a]; j++) {
        		int v=fleg[j];
        		chkmin(nd[a], max(0, nd[v] - 1));
        	}
        	for (int j = ql[a]; j<qr[a]; j++) {
        		int v=fseg[j];
        		chkmin(nd[a], nd[v] + 1);
        	}
		}

        for (int i=0;i<n;i++) {
        	int a=ord[i];
        	for (int j = rl[a]; j<rr[a]; j++) {
        		int v=fgeg[j];
				chkmin(nd[v], max(0, nd[a] - 1));
			}
        	for (int j = ql[a]; j<qr[a]; j++) {
        		int v=fseg[j];
				chkmin(nd[v], nd[a] + 1);
        	}
		}

        for (int i = 1; i <= n; i++)
            if (!nd[i]) chkmin(res[i], j);
    }
    for (int i = 1; i <= n; i++) {
        int ans = h[i] + h[i] - min(h[i], res[i]);
        printf("%d ", ans);
    }
    printf("\n");
    return (0-0); //<3
}