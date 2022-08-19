#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int n, q;
int a[100005], b[100005];

pi spt[17][100005];
int lg[100005];

int query(int s, int e){
	int l = lg[e-s+1];
	pi w = max(spt[l][s], spt[l][e-(1<<l)+1]);
	return w.second;
}

lint f(int s, int e){
	if(s > e) return 0;
	int w = query(s, e);
	return 1ll * (w - s + 1) * (e - w + 1) * b[w] + f(s, w-1) + f(w+1, e);
}

int main(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	int l = 0;
	for(int i=1; i<n; i++){
		b[i] = abs(a[i+1] - a[i]);
		spt[0][i] = pi(b[i], i);
		while((2 << l) <= i) l++;
		lg[i] = l;
	}
	for(int i=1; i<17; i++){
		for(int j=1; j<n; j++){
			spt[i][j] = spt[i-1][j];
			if(j + (1<<(i-1)) < n) spt[i][j] = max(spt[i][j], spt[i-1][j + (1<<(i-1))]);
		}
	}
	while(q--){
		int s, e;
		scanf("%d %d",&s,&e);
		printf("%lld\n", f(s, e-1));
	}
}