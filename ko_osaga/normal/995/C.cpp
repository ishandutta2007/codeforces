#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 200005;

int n;
pi a[MAXN];
int l[MAXN], r[MAXN], ret[MAXN];

pi operator+(const pi &a, const pi &b){
	return pi(a.first + b.first, a.second + b.second);
}

pi operator-(const pi &a, const pi &b){
	return pi(a.first - b.first, a.second - b.second);
}

lint sz(pi a){
	return 1ll * a.first * a.first + 1ll * a.second * a.second;
}

void dfs(int x, int v){
	if(x < n){
		ret[x] = v;
		return;
	}
	if(a[l[x]] - a[r[x]] == a[x]){
		dfs(l[x], v);
		dfs(r[x], -v);
	}
	else{
		dfs(l[x], v);
		dfs(r[x], v);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	if(n == 1){
		puts("1");
		return 0;
	}
	int p1 = 0, p2 = 1, piv = n;
	for(int i=2; i<n; i++){
		lint rad = max({sz(a[p1]), sz(a[p2]), sz(a[i])});
		if(sz(a[p1] + a[i]) <= rad){
			l[piv] = p1; r[piv] = i;
			a[piv] = a[p1] + a[i];
			tie(p1, p2) = pi(piv, p2);
		}
		else if(sz(a[p1] - a[i]) <= rad){
			l[piv] = p1; r[piv] = i;
			a[piv] = a[p1] - a[i];
			tie(p1, p2) = pi(piv, p2);
		}
		else if(sz(a[p2] + a[i]) <= rad){
			l[piv] = p2; r[piv] = i;
			a[piv] = a[p2] + a[i];
			tie(p1, p2) = pi(p1, piv);
		}
		else if(sz(a[p2] - a[i]) <= rad){
			l[piv] = p2; r[piv] = i;
			a[piv] = a[p2] - a[i];
			tie(p1, p2) = pi(p1, piv);
		}
		else if(sz(a[p1] + a[p2]) <= rad){
			l[piv] = p1; r[piv] = p2;
			a[piv] = a[p1] + a[p2];
			tie(p1, p2) = pi(piv, i);
		}
		else if(sz(a[p1] - a[p2]) <= rad){
			l[piv] = p1; r[piv] = p2;
			a[piv] = a[p1] - a[p2];
			tie(p1, p2) = pi(piv, i);
		}
		else assert(0);
		piv++;
	}
	if(sz(a[p1] + a[p2]) < sz(a[p1] - a[p2])){
		dfs(p1, 1);
		dfs(p2, 1);
	}
	else{
		dfs(p1, 1);
		dfs(p2, -1);
	}
	for(int i=0; i<n; i++) printf("%d ", ret[i]);
}