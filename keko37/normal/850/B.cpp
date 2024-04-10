#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 2000020;

typedef long long llint;

llint n, x, y, sol=1000000000000000000LL;
llint p[MAXN], sum[MAXN];

int main () {
	cin >> n >> x >> y;
	for (int i=0; i<n; i++) {
		int inp;
		scanf("%d", &inp);
		p[inp]++;
		sum[inp]+=inp;
	}
	for (int i=0; i<MAXN; i++) {
		p[i]+=p[i-1];
		sum[i]+=sum[i-1];
	}
	for (llint len=2; len<MAXN; len++) {
		llint val=min(x/y, len-1);
		llint res=0;
		for (llint i=len; i<MAXN; i+=len) {
			llint br=p[i]-p[i-val-1];
			llint d=i*br-(sum[i]-sum[i-val-1]);
			res+=y*d;
			res+=x*(p[i-val-1]-p[i-len]);
		}
		sol=min(sol, res);
	}
	cout << sol;
	return 0;
}