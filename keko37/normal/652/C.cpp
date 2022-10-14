#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

long long n, m, a, b, sol;
long long l[300005];
long long in[300005];
vector <long long> v[300005];
long long dp[300005];

int main () {
	scanf("%d%d", &n, &m);
	for (long long i=0; i<n; i++) {
		cin >> l[i];
		in[l[i]]=i;
	}
	for (long long i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (long long i=0; i<n; i++) {
		long long maxin=0;
		for (long long j=0; j<v[l[i]].size(); j++) {
			if (in[v[l[i]] [j]]<in[l[i]]) maxin=max(maxin, in[v[l[i]] [j]]+1);
		}
		if (i) maxin=max(maxin, dp[i-1]);
		dp[i]=maxin;
	}
	for (long long i=0; i<n; i++) {
		sol+=i-dp[i]+1;
	}
	cout << sol;
	return 0;
}