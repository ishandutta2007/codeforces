#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

typedef pair <int, int> par;
#define X first
#define Y second
#define TRACE(x) cerr << #x << " = " << x << endl;

const int MAXN = 200005;
const int LOG = 20;
int n, m, q, a, b, povezani, brojac;
int timer=1, boja, sol=1;
vector <int> v[MAXN];
vector <int> graf[MAXN];
vector <par> upit[MAXN];
map <par, bool> mp;
map <par, int> dupli;
int d[MAXN];
int s[MAXN];
int disc[MAXN];
int low[MAXN];
int comp[MAXN];
int bio[MAXN];
int dub[MAXN];
int dp[MAXN] [LOG];
int djecaup[MAXN];
int djecadown[MAXN];
int pov[MAXN];
int biozasol[MAXN];
string out[5]={"No", "Yes"};

inline bool jedupli (int iz, int u) {
	return dupli.find(make_pair(iz, u))!=dupli.end() && dupli[make_pair(iz, u)]>1;
}

int mostovi (int cvor, int rod) {
	if (disc[cvor]>0) return disc[cvor];
	disc[cvor]=timer++;
	low[cvor]=disc[cvor];
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==rod) continue;
		bool ok = disc[sus]==0;
		int t=mostovi(sus, cvor);
		if (ok && disc[cvor]<t && !jedupli(cvor, sus)) {
			mp[make_pair(cvor, sus)]=1;
			mp[make_pair(sus, cvor)]=1;
		}
		low[cvor]=min(low[cvor], t);
	}
	return low[cvor];
}

void nadi_mostove () {
	for (int i=1; i<=n; i++) {
		if (disc[i]==0) mostovi(i, 0);
	}
}

inline bool jemost (int iz, int u) {
	return mp.find(make_pair(iz, u))!=mp.end();
}

void spoji (int cvor) {
	if (comp[cvor]>0) return;
	comp[cvor]=boja;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (!jemost(cvor, sus)) spoji(v[cvor] [i]);
	}
}

void oboji () {
	for (int i=1; i<=n; i++) {
		if (comp[i]==0) {
			boja++;
			spoji(i);
		}
	}
}

void bridovi (int cvor) {
	if (bio[cvor]) return;
	bio[cvor]=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (jemost(cvor, sus)) {
			graf[comp[cvor]].push_back(comp[sus]);
		}
		bridovi(sus);
	}
}

void nadi_bridove () {
	for (int i=1; i<=n; i++) {
		if (bio[i]==0) bridovi(i);
	}
}

void rootaj (int cvor, int rod) {
	if (rod==0) dub[cvor]=1; else dub[cvor]=dub[rod]+1;
	dp[cvor] [0]=rod;
	pov[cvor]=povezani;
	for (int i=0; i<graf[cvor].size(); i++) {
		int sus=graf[cvor] [i];
		if (sus==rod) continue;
		rootaj(sus, cvor);
	}
}

void rootaj_sve () {
	for (int i=1; i<=boja; i++) {
		if (dub[i]==0) {
			povezani++;
			rootaj(i, 0);
		}
	}
}

void jump () {
	for (int i=1; i<LOG; i++) {
		for (int j=1; j<=boja; j++) {
			dp[j] [i]=dp[dp[j] [i-1]] [i-1];
		}
	}
}

int digni (int cvor, int kol) {
	for (int pot=0; kol; pot++) {
		if (kol&1) cvor=dp[cvor] [pot];
		kol/=2;
	}
	return cvor;
}

int lca (int aa, int bb) {
	if (dub[aa]<dub[bb]) swap(aa, bb);
	aa=digni(aa, dub[aa]-dub[bb]);
	if (aa==bb) return aa;
	for (int i=LOG-1; i>=0; i--) {
		if (dp[aa] [i]!=dp[bb] [i]) {
			aa=dp[aa] [i];
			bb=dp[bb] [i];
		}
	}
	return dp[aa] [0];
}

void svojstva () {
	for (int i=0; i<q; i++) {
		if (comp[s[i]]==comp[d[i]]) continue;
		s[i]=comp[s[i]];
		d[i]=comp[d[i]];
		if (pov[s[i]]!=pov[d[i]]) sol=0;
		int an=lca(s[i], d[i]);
		if (an==s[i]) {
			upit[s[i]].push_back(make_pair(0, 0));
			upit[d[i]].push_back(make_pair(1, 0));
		} else if (an==d[i]) {
			upit[d[i]].push_back(make_pair(0, 1));
			upit[s[i]].push_back(make_pair(1, 1));
		} else {
			upit[an].push_back(make_pair(0, 0));
			upit[d[i]].push_back(make_pair(1, 0));
			upit[an].push_back(make_pair(0, 1));
			upit[s[i]].push_back(make_pair(1, 1));
		}
	}
}

pair <int, int> dfs (int cvor) {
	biozasol[cvor]=1;
	int up=0, down=0;
	for (int i=0; i<graf[cvor].size(); i++) {
		int sus=graf[cvor] [i];
		if (sus==dp[cvor] [0]) continue;
		par t=dfs(sus);
		up+=t.X; down+=t.Y;
	}
	for (int i=0; i<upit[cvor].size(); i++) {
		par pii=upit[cvor] [i];
		if (pii.X==0) {
			if (pii.Y==0) down--; else up--;
		} else {
			if (pii.Y==0) down++; else up++;
		}
	}
	if (up && down) sol=0;
	return make_pair(up, down);
}

void nadi_rjesenje () {
	for (int i=1; i<=boja; i++) {
		if (biozasol[i]==0) dfs(i);
	}
}

int main () {
	scanf("%d%d%d", &n, &m, &q);
	for (int i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
		dupli[make_pair(a, b)]++;
		dupli[make_pair(b, a)]++;
	}
	for (int i=0; i<q; i++) {
		scanf("%d%d", &s[i], &d[i]);
	}
	nadi_mostove();
	oboji();
	nadi_bridove();
	rootaj_sve();
	jump();
	svojstva();
	if (sol==0) {
		cout << "No";
		return 0;
	}
	nadi_rjesenje();
	/*for (map <par, bool> :: iterator it=mp.begin(); it!=mp.end(); it++) {
		cout << "most " << it->X.X << " " << it->X.Y << endl;
	}*/
	/*for (int i=1; i<=boja; i++) {
		cout << "bla " << i << " " << dub[i] << endl;
	}*/
	cout << out[sol];
	return 0;
}