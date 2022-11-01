#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

unordered_map<int,int> mn;
int n, k, q;
int a[5005];

int main() {
	scanf("%d%d", &n, &k);
	FO(i,0,n) {
		scanf("%d", a+i);
		FO(j,0,k+1) if (!mn.count(a[i]*j) || mn[a[i]*j] > j) mn[a[i]*j] = j;
	}
	scanf("%d", &q);
	FO(Z,0,q) {
		int x, r=21; scanf("%d", &x);
		FO(i,0,n) {
			FO(j,0,k+1) if (mn.count(x-a[i]*j)) r = min(r, j+mn[x-a[i]*j]);
		}
		if (r <= k) printf("%d\n", r);
		else printf("-1\n");
	}
}