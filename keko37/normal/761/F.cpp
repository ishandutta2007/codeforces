#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

typedef long long llint;

const llint MAXN = 1005;
const llint MAXK = 300005;

llint n, m, k, sol=100000000000000000LL;
char l[MAXN] [MAXN], c[MAXK];
llint dp[MAXN] [MAXN] [27];
llint smanji[MAXN] [MAXN];
llint povecaj[MAXN] [MAXN];
llint dist[MAXN] [MAXN];
llint distsum[MAXN] [MAXN], dpsum[MAXN] [MAXN] [27];
llint x1[MAXK], y1[MAXK], x2[MAXK], y2[MAXK];
vector <llint> v[27];

llint llabs (llint val) {
	if (val>0) return val; return -val;
}

int main () {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> l[i] [j];
			dp[i] [j] [l[i] [j]-'a']+=k;
		}
	}
	for (int i=0; i<k; i++) {
		scanf("%lld%lld%lld%lld", &x1[i], &y1[i], &x2[i], &y2[i]);
		x1[i]--; y1[i]--; x2[i]--; y2[i]--;
		cin >> c[i];
		v[c[i]-'a'].push_back(i);
		smanji[x1[i]] [y1[i]]++; smanji[x2[i]+1] [y2[i]+1]++;
		smanji[x2[i]+1] [y1[i]]--; smanji[x1[i]] [y2[i]+1]--;
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (j) smanji[j] [i]+=smanji[j-1] [i];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (j) smanji[i] [j]+=smanji[i] [j-1];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int h=0; h<26; h++) {
				if (dp[i] [j] [h]) dp[i] [j] [h]-=smanji[i] [j];
			}
		}
	}
	for (int h=0; h<26; h++) {
		memset(povecaj, 0, sizeof povecaj);
		for (int i=0; i<v[h].size(); i++) {
			llint ind=v[h] [i];
			povecaj[x1[ind]] [y1[ind]]++; povecaj[x2[ind]+1] [y2[ind]+1]++;
			povecaj[x2[ind]+1] [y1[ind]]--; povecaj[x1[ind]] [y2[ind]+1]--;
		}
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (j) povecaj[j] [i]+=povecaj[j-1] [i];
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (j) povecaj[i] [j]+=povecaj[i] [j-1];
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				dp[i] [j] [h]+=povecaj[i] [j];
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int h=0; h<26; h++) {
				dist[i] [j]+=llabs(l[i] [j]-'a'-h)*dp[i] [j] [h];
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			distsum[i] [j]=dist[i] [j];
			if (i) distsum[i] [j]+=distsum[i-1] [j];
			if (j) distsum[i] [j]+=distsum[i] [j-1];
			if (i && j) distsum[i] [j]-=distsum[i-1] [j-1];
			for (int h=0; h<26; h++) {
				dpsum[i] [j] [h]=dp[i] [j] [h];
				if (i) dpsum[i] [j] [h]+=dpsum[i-1] [j] [h];
				if (j) dpsum[i] [j] [h]+=dpsum[i] [j-1] [h];
				if (i && j) dpsum[i] [j] [h]-=dpsum[i-1] [j-1] [h];
			}
		}
	}
	for (int i=0; i<k; i++) {
		llint res=distsum[n-1] [m-1]-distsum[x2[i]] [y2[i]];
		if (y1[i]) res+=distsum[x2[i]] [y1[i]-1];
		if (x1[i]) res+=distsum[x1[i]-1] [y2[i]];
		if (x1[i] && y1[i]) res-=distsum[x1[i]-1] [y1[i]-1];
		for (int h=0; h<26; h++) {
			llint prav=dpsum[x2[i]] [y2[i]] [h];
			if (y1[i]) prav-=dpsum[x2[i]] [y1[i]-1] [h];
			if (x1[i]) prav-=dpsum[x1[i]-1] [y2[i]] [h];
			if (x1[i] && y1[i]) prav+=dpsum[x1[i]-1] [y1[i]-1] [h];
			res+=llabs(c[i]-'a'-h)*prav;
		}

		sol=min(sol, res);
	}
	cout << sol;
	return 0;
}