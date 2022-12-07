#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
const int inf = 0x3f3f3f3f;

struct SAM{ // [0,L] , 0 is virtual , 1 is rt , init!!
    static const int N = 201010 , M = 26;
    int par[N] , l[N] , ne[N][M], pos[N], cnt[N], tp[N];
    int rt , last , L;
    void add(int c, int v){
        int p = last , np = ++L;
        pos[np] = v;
        fill(ne[np] , ne[np] + M , 0);
        l[np] = l[p] + 1;
        last = np;
        while(p && !ne[p][c]) ne[p][c] = np , p = par[p];
        if(!p) par[np] = rt;
        else{
            int q = ne[p][c];
            if(l[q] == l[p] + 1) par[np] = q;
            else{
                int nq = ++L;
                pos[nq] = v;
                l[nq] = l[p] + 1;
                copy(ne[q] , ne[q] + M , ne[nq]);
                par[nq] = par[q];
                par[q] = par[np] = nq;
                while(p && ne[p][c] == q) ne[p][c] = nq , p = par[p];
            }
        }
    }
    void ini(){
        rt = last = L = 1;
        fill(ne[rt] , ne[rt] + M , 0);
        l[0] = -1;
    }

    void gao(int n) {
    	for (int i = 0; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= L; i++) cnt[l[i]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		for (int i = 1; i <= L; i++) tp[cnt[l[i]]--] = i;
	}
} g1, g2;

char s[N];
int pr[N], sf[N];

bool judge() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int u = g1.rt;
	for (int i = 1; i <= n; i++) pr[i] = sf[i] = -1;
	for (int i = 1; i <= n; i++) {
		int c = s[i] - 'A';
		if (!g1.ne[u][c]) break;
		u = g1.ne[u][c];
		pr[i] = g1.pos[u];
	}
	u = g2.rt;
	for (int i = n; i >= 1; i--) {
		int c = s[i] - 'A';
		if (!g2.ne[u][c]) break;
		u = g2.ne[u][c];
		sf[i] = g2.pos[u];
	}
	for (int i = 1; i < n; i++) {
		if (pr[i] == -1 || sf[i + 1] == -1) continue;
		if (pr[i] < sf[i + 1]) return true;
	}
	return false;
}

int main() {
	g1.ini(); g2.ini();
	scanf("%s", s + 1); int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) g1.add(s[i] - 'A', i);
	for (int i = n; i >= 1; i--) g2.add(s[i] - 'A', i);
	g1.gao(n); g2.gao(n);
	for (int ii = g1.L; ii >= 1; ii--) {
		int i = g1.tp[ii];
		g1.pos[g1.par[i]] = min(g1.pos[g1.par[i]], g1.pos[i]);
	}
	for (int ii = g2.L; ii >= 1; ii--) {
		int i = g2.tp[ii];
		g2.pos[g2.par[i]] = max(g2.pos[g2.par[i]], g2.pos[i]);
	}
	g1.gao(n); g2.gao(n);
	int m; scanf("%d", &m);
	int ans = 0;
	while (m--) ans += judge();
	printf("%d\n", ans);
	return 0;
}