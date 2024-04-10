#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 2005;
const int INF = 1000000007;

int n, ok=1;
llint bio[MAXN], l[MAXN] [MAXN], d[MAXN], par[MAXN];
vector < pair <int, int> > v[MAXN];

int nadi (int cvor) {
	if (par[cvor]==cvor) return cvor;
	par[cvor]=nadi(par[cvor]);
	return par[cvor];
}

void spoji (int a, int b) {
	a=nadi(a); b=nadi(b);
	if (a==b) {
		ok=0;
		return;
	}
	par[b]=a;
}

void dfs (int cvor, int rod) {
	//cout << "bok " << cvor << " " << rod << endl;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].first;
		if (sus==rod) continue;
		d[sus]=d[cvor]+v[cvor] [i].second;
		dfs(sus, cvor);
	}
}

void check () {
	for (int i=1; i<=n; i++) {
		memset(d, -1, sizeof d);
		d[i]=0;
		dfs(i, 0);
		for (int j=1; j<=n; j++) {
			if (l[i] [j]!=d[j]) {
				cout << "NO";
				ok=0;
				return;
			}
		}
	}
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			scanf("%d", &l[i] [j]);
		}
	}
	for (int i=1; i<=n; i++) {
		par[i]=i;
		if (l[i] [i]!=0) {
			cout << "NO";
			return 0;
		}
		for (int j=1; j<=n; j++) {
			if (l[i] [j]==0 && i!=j) {
				cout << "NO";
				return 0;
			}
		}
	}
	for (int ii=0; ii<n-1; ii++) {
		int ind;
		for (int i=1; i<=n; i++) {
			if (bio[i]==0) {
				ind=i;
				break;
			}
		}
		int maxi=-1, naj;
		for (int i=1; i<=n; i++) {
			if (i!=ind && bio[i]==0 && l[ind] [i]>maxi) {
				maxi=l[ind] [i];
				naj=i;
			} 
		}
		int mini=INF, sus;
		for (int i=1; i<=n; i++) {
			if (i!=naj && bio[i]==0 && l[naj] [i]<mini) {
				mini=l[naj] [i];
				sus=i;
			}
		}
		spoji(naj, sus);
		if (!ok) {
			cout << "NO";
			return 0;
		}
		v[naj].push_back(make_pair(sus, mini));
		v[sus].push_back(make_pair(naj, mini));
		bio[naj]=1;
	}
	/*for (int i=1; i<=n; i++) {
		cout << i << "  ";
		for (int j=0; j<v[i].size(); j++) {
			cout << v[i] [j].second << " ";
		}
		cout << endl;
	}*/
	check();
	if (ok) cout << "YES";
	return 0;
}