#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;

ll getMinDiff(vi & v, int curr){
	sort(v.begin(), v.end());
	int x = v[v.size() >> 1];
	long long ans = 0;
	for(int y : v) ans += abs(x - y) - abs(curr - y);
	return ans;
}

vector<int> pos[N], V;
int a[N];
int main(){
	int n, m;
	sd(n); sd(m);
	long long ans = 0;
	for(int i = 1; i <= m;i ++){ sd(a[i]); pos[a[i]].pb(i); if(i >= 2) ans += abs(a[i] - a[i - 1]);}
	ll ANS = ans;
	for(int x = 1; x <= n; x++){
		V.clear();
		for(int i : pos[x]){
			int j = i - 1;
			if(j >= 1 && j <= m && a[j] != x)
				V.pb(a[j]);
			j = i + 1;
			if(j >= 1 && j <= m && a[j] != x)
				V.pb(a[j]);
		}
		if(!V.empty()){
			ll p = getMinDiff(V, x);
			ans = min(ans, ANS + getMinDiff(V, x));
		}
	}
	printf("%lld\n", ans);
}