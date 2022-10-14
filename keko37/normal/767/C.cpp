#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long int llint;

const int MAXN = 3000005;

int n, a, b, x, root, ti;
int naso;
llint t[MAXN], sum[MAXN], crni[MAXN];
vector <int> v[MAXN];

llint zasum (int cvor, int par) {
	llint res=t[cvor];
	for (int i=0; i<v[cvor].size(); i++) {
		if (v[cvor] [i]!=par) res+=zasum(v[cvor] [i], cvor);
	}
	sum[cvor]=res;
	return res;
}

void dfs (int cvor, int par) {
	if (sum[cvor]*3==sum[root]) crni[cvor]=cvor;
	int cnt=0, loca, locb;
	for (int i=0; i<v[cvor].size(); i++) {
		if (v[cvor] [i]==par) continue;
		int sus=v[cvor] [i];
		dfs(sus, cvor);
		if (naso) return;
		if (crni[sus]) {
			crni[cvor]=crni[sus];
			cnt++;
			if (cnt==1) {
				loca=crni[sus];
			} else if (cnt==2) {
				locb=crni[sus];
				a=loca;
				b=locb;
				naso=1;
				break;
			}
		}
	}
	if (!naso && cvor!=root && cnt && sum[cvor]*3==2*sum[root]) {
		locb=cvor;
		naso=1;
	}
	if (naso) {
		a=loca;
		b=locb;
	}
}

int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &x, &ti);
		t[i]=ti;
		if (x!=0) {
			v[i].push_back(x);
			v[x].push_back(i);
		} else {
			root=i;
		}
	}
	zasum(root, 0);
	dfs(root, 0);
	if (naso) {
		cout << a << " " << b;
	} else {
		cout << -1;
	}
	return 0;
}