#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, k, q, type, id, x, total;
int l[150005];
int p[150005];
vector <int> v;
int fen[150005];

void ubaci (int val, int kol) {
	for (; val<150005; val+=val&-val) fen[val]+=kol;
}

int upit (int val) {
	int res=0;
	for (; val>0; val-=val&-val) res+=fen[val];
	return res;
}

int main () {
	cin >> n >> k >> q;
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
		v.push_back(l[i]);
	}
	sort(v.begin(), v.end());
	for (int i=0; i<q; i++) {
		scanf("%d%d", &type, &id);
		if (type==1) {
			ubaci(lower_bound(v.begin(), v.end(), l[id])-v.begin()+1, 1);
			p[id]=1;
			total++;
		} else {
			x=total-upit(lower_bound(v.begin(), v.end(), l[id])-v.begin()+1)+1;
			if (x<=k && p[id]) printf("YES\n"); else printf("NO\n");
		}
	}
	return 0;
}