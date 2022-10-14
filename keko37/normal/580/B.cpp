#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
typedef long long int llint;

int n, d;
pair <int, int> l[100005];
int m[100005];
int s[100005];
llint sum[100005];
llint sol;

int main () {
	cin >> n >> d;
	for (int i=0; i<n; i++) {
		scanf("%d%d", &l[i].first, &l[i].second);
	}
	sort (l, l+n);
	sum[0]=l[0].second;
	for (int i=0; i<n; i++) {
		m[i]=l[i].first;
		s[i]=l[i].second;
		if (i) sum[i]=sum[i-1]+s[i];
	}
	for (int i=0; i<n; i++) {
		int x=upper_bound(m, m+n, m[i]-d)-m;
		if (x==0) {
			sol=max(sol, sum[i]);
		} else {
			sol=max(sol, sum[i]-sum[x-1]);
		}
	}
	cout << sol;
	return 0;
}