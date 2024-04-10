#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 505;

int n, m, naso;
int bio[MAXN], doso[MAXN];
vector <int> v[MAXN], cik, t;

void dfs (int x) {
	if (naso) return;
	bio[x]=1;
	for (int i=0; i<v[x].size(); i++) {
		if (naso) return;
		int sus=v[x] [i];
		if (bio[sus]!=2) doso[sus]=x;
		if (bio[sus]==0) {
			dfs(sus);
		} else if (bio[sus]==1) {
			naso=1;
			int curr=x;
			do {
				cik.push_back(curr);
				curr=doso[curr];
			} while (curr!=x);
		}
		if (naso) return;
	}
	bio[x]=2;
}

void sredi (int x, int y) {
	for (int i=0; i<v[x].size(); i++) {
		if (v[x] [i]==y) {
			v[x].erase(v[x].begin()+i);
			break;
		}
	}
	v[x].push_back(y);
}

bool ima () {
	naso=0;
	memset(bio, 0, sizeof bio);
	cik.clear();
	for (int i=1; i<=n; i++) {
		if (!bio[i]) dfs(i);
	}
	return naso;
}

void nadi () {
	t=cik;
	t.push_back(t[0]);
	for (int i=1; i<t.size(); i++) {
		v[t[i]].pop_back();
		if (!ima()) {
			cout << "YES";
			return;
		}
		v[t[i]].push_back(t[i-1]);
	}
	cout << "NO";
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) dfs(i);
	}
	if (!naso) {
		cout << "YES";
		return 0;
	}
	sredi(cik[0], cik.back());
	for (int i=1; i<cik.size(); i++) {
		sredi(cik[i], cik[i-1]);
	}
	nadi();
	return 0;
}