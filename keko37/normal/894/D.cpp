#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int n, m;
int l[MAXN];
vector <llint> v[MAXN], sum[MAXN];

void spoji (int cvor) {
	v[cvor].push_back(0);
	sum[cvor].push_back(0);
	if (cvor*2>n) return;
	int p1=0, p2=0;
	int lef=cvor*2, rig=cvor*2+1;
	while (p1<v[lef].size() || p2<v[rig].size()) {
		while (p1<v[lef].size() && p2==v[rig].size() || p1<v[lef].size() && v[lef] [p1]+l[lef]<=v[rig] [p2]+l[rig]) {
			v[cvor].push_back(v[lef] [p1]+l[lef]);
			p1++;
		}
		while (p2<v[rig].size() && p1==v[lef].size() || p2<v[rig].size() && v[lef] [p1]+l[lef]>=v[rig] [p2]+l[rig]) {
			v[cvor].push_back(v[rig] [p2]+l[rig]);
			p2++;
		}
	}
	for (int i=1; i<v[cvor].size(); i++) {
		sum[cvor].push_back(sum[cvor] [i-1]+v[cvor] [i]);
	}
}

llint upit (int cvor, llint h) {
	llint sol=0;
	int curr=cvor, doso, ind, orgh=h, pos;
	while (curr) {
		if (curr==cvor) {
			ind=lower_bound(v[curr].begin(), v[curr].end(), h)-v[curr].begin();
			sol+=ind==0?0LL:ind*h-sum[curr] [ind-1];
		} else {
			sol+=h;
			if (doso==curr*2) pos=curr*2+1; else pos=curr*2;
			ind=lower_bound(v[pos].begin(), v[pos].end(), h-l[pos])-v[pos].begin();
			sol+=ind==0?0LL:ind*(h-l[pos])-sum[pos] [ind-1];
		}
		doso=curr;
		h-=l[curr];
		if (h<=0) break;
		curr/=2;
	}
	return sol;
}

int main () {
	cin >> n >> m;
	for (int i=2; i<=n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=n; i>=1; i--) {
		spoji(i);
	}
	for (int i=0; i<m; i++) {
		int a, h;
		scanf("%d%d", &a, &h);
		printf("%I64d\n", upit(a, h));
	}
	return 0;
}