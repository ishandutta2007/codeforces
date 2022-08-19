#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

int gcd(int x, int y){ return y ? gcd(y, x%y) : x; }

int spt[17][100005], lg[100005];
int n, a[100005];
vector<pi> v;

int range_gcd(int s, int e){
	int l = lg[e-s+1];
	return gcd(spt[l][s], spt[l][e-(1<<l)+1]);
}

int main(){
	scanf("%d",&n);
	int p = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		spt[0][i] = a[i];
		while((2 << p) <= i) p++;
		lg[i] = p;
	}
	for(int i=1; i<17; i++){
		for(int j=1; j<=n; j++){
			spt[i][j] = spt[i-1][j];
			if(j + (1<<(i-1)) <= n){
				spt[i][j] = gcd(spt[i][j], spt[i-1][j+(1<<(i-1))]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		int cur = a[i], stp = i;
		while(1){
			int s = stp, e = n;
			while(s != e){
				int m = (s+e+1)/2;
				if(range_gcd(i, m) != cur) e = m-1;
				else s = m;
			}
			v.push_back(pi(cur, s+1 - stp));
			if(s == n) break;
			cur = range_gcd(i, s+1);
			stp = s+1;
		}
	}
	sort(v.begin(), v.end());
	vector<pi> w;
	for(int i=0; i<v.size(); i++){
		int e = i;
		pi k(v[e].first, 0);
		while(e < v.size() && v[e].first == v[i].first){
			k.second += v[e].second;
			e++;
		}
		w.push_back(k);
		i = e-1;
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		scanf("%d",&x);
		auto l = lower_bound(w.begin(), w.end(), pi(x, -1));
		if(l != w.end() && l->first == x) printf("%lld\n", l->second);
		else puts("0");
	}
}