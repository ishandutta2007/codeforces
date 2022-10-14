#include<iostream>
#include<cstring>

using namespace std;
typedef long long int llint;

int n, m, k;
int l[20];
int p[20] [20];
llint bio[19] [(1<<19)];
llint sol;

int bits (int x) {
	int res=0;
	for (; x; x/=2) res+=x%2;
	return res;
}

llint f (int pos, int mask) {
	if (bio[pos] [mask]!=-1) return bio[pos] [mask];
	if (bits(mask)==m) return 0;
	llint res=0;
	for (int i=0; i<n; i++) {
		if (!(mask & (1<<i) )) res=max(res, f(i+1, mask | (1<<i) )+l[i+1]+p[pos] [i+1]);
	}
	bio[pos] [mask]=res;
	return res;
}

int main () {
	memset (bio, -1, sizeof bio);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> l[i];
	}
	for (int i=0; i<k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		p[a] [b]=c;
	}
	for (int i=1; i<=n; i++) {
		sol=max(sol, f(i, (1<<(i-1)))+l[i]);
	}
	cout << sol;
	return 0;
}