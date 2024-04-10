#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
pair<int,int> x[200005]; int o[200005];
int n,m;
int gn(int i, int l) {
	int r=lower_bound(x,x+n,make_pair(x[i].first+l+1,-1))-x-1;
	if (r==i) r=lower_bound(x,x+n,make_pair(x[i].first-l,-1))-x;
	return r;
}
int main() {
	scanf("%d %d", &n, &m);
	FO(i,0,n) scanf("%d", &x[i].first), x[i].second = i+1;
	sort(x,x+n);
	FO(i,0,n) o[x[i].second]=i;
	FO(Z,0,m) {
		int i,l; scanf("%d%d", &i, &l); i=o[i];
		while (gn(i,l) != i) {
			int ni = gn(i,l), nl = l-abs(x[ni].first-x[i].first);
			if (gn(ni,nl) == i) l %= 2*abs(x[ni].first-x[i].first);
			else i=ni,l=nl;
		}
		printf("%d\n", x[i].second);
	}
}