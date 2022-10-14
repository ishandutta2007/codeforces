#include<iostream>
#include<vector>
#include<cstdio>
#include<map>

using namespace std;

const int MAXN = 300005;
int n, m, timer=1, cnt, naso, sol;
int a, b, c;
int disc[MAXN];
int low[MAXN];
int comp[MAXN];
int ima[MAXN];
int bio[MAXN];
string out[5]={"NO", "YES"};
map < pair <int, int>, bool > mp;

struct brid {
	int sus, ima, most;
} br;
vector <brid> v[MAXN];

int dfs (int cvor, int par) {
	if (disc[cvor]>0) return disc[cvor];
	disc[cvor]=timer++;
	low[cvor]=disc[cvor];
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].sus;
		if (sus==par) continue;
		bool ok=(disc[sus]==0);
		int t=dfs(sus, cvor);
		if (ok && disc[cvor]<t) {
			mp[make_pair(cvor, sus)]=1;
			mp[make_pair(sus, cvor)]=1;
		}
		low[cvor]=min(low[cvor], t);
	}
	return low[cvor];
}

int dfs2 (int cvor, int boja) {
	comp[cvor]=boja;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].sus;
		if (mp.find(make_pair(cvor, sus))==mp.end()) {
			ima[boja]|=v[cvor] [i].ima;
		}
		if (comp[sus]==0 && mp.find(make_pair(cvor, sus))==mp.end()) {
			dfs2(sus, boja);
		}
	}
}

int dfs3 (int cvor) {
	bio[cvor]=1;
	if (comp[b]==comp[cvor] && naso>0) sol=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].sus;
		if (bio[sus]) continue;
		if (mp.find(make_pair(cvor, sus))==mp.end()) {
			dfs3(sus);
		} else {
			if (ima[comp[sus]]) naso++;
			if (v[cvor] [i].ima==1) naso++;
			dfs3(sus);
			if (v[cvor] [i].ima==1) naso--;
			if (ima[comp[sus]]) naso--;
		}
	}
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		br.sus=b; br.ima=c; br.most=0;
		v[a].push_back(br);
		br.sus=a; br.ima=c; br.most=0;
		v[b].push_back(br);
	}
	cin >> a >> b;
	dfs(1, -1);
	for (int i=1; i<=n; i++) {
		if (comp[i]==0) {
			cnt++;
			dfs2(i, cnt);
		}
	}
	if (ima[comp[a]] || ima[comp[b]]) {
		cout << "YES";
	} else {
		dfs3(a);
		cout << out[sol];
	}
	return 0;
}