#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;
typedef long double llf;
const lint mod = 1e9 + 7;

int n, p;
pi a[100005];

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

bool trial(llf x){
	llf tot = 0;
	for(int i=0; i<n; i++){
		llf t = max((llf)0.0, x * a[i].first - a[i].second) / p;
		tot += t;
	}
	return tot <= x;
}

int main(){
	cin >> n >> p;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
	}
	llf s = 0, e = 1e18;
	for(int i=0; i<100; i++){
		llf m = (s+e)/2;
		if(trial(m)) s = m;
		else e = m;
	}
	if(s > 9e17){
		cout << -1;
		return 0;
	}
	printf("%.15Lf\n", s);
}