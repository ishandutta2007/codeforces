#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

int n, m, q, cnt=1, e;
int l[MAXN], bio[MAXN], p[MAXN];
llint sum[MAXN];
vector <int> v[MAXN];

llint get (int x, int y) {
	if (x>y) return 0;
	if (x==0) return sum[y]; return sum[y]-sum[x-1];
}

void dfs (int x) {
	bio[x]=1;
	for (int i=0; i<v[x].size(); i++) {
		int sus=v[x] [i];
		if (sus==p[x]) continue;
		if (bio[sus]==0) {
			p[sus]=x;
			dfs(sus);
		} else if (bio[sus]==1) {
			int mini=MAXN, maxi=0;
			for (int curr=x; ; curr=p[curr]) {
				mini=min(mini, curr);
				maxi=max(maxi, curr);
				if (curr==sus) break;
			}
			l[mini]=maxi;
		}
	}
	bio[x]=2;
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		l[i]=n+1;
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) dfs(i);
	}
	for (int i=n-1; i>=1; i--) {
		l[i]=min(l[i], l[i+1]);
	}
	for (int i=1; i<=n; i++) {
		l[i]--;
		sum[i]=sum[i-1]+l[i];
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		llint x, y;
		scanf("%I64d%I64d", &x, &y);
		llint sol=0;
		llint ind=lower_bound(l+1, l+n+1, y)-l;
		ind=max(ind, x);
		ind=min(ind, y+1);
		sol+=(y-ind+1)*y;
		sol+=get(x, ind-1);
		sol-=(x+y)*(y-x+1)/2-y+x-1;
		printf("%I64d\n", sol);
	}
	return 0;
}