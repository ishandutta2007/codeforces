#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int n;
lint a[200005], b[200005];

struct cht{
	lint pa[200005], pb[200005];
	int s, e;
	llf crs(int x, int y){
		return (llf)(pb[y] - pb[x]) / (pa[x] - pa[y]);
	}
	void add(lint x, lint y){
		tie(pa[e], pb[e]) = pi(x, y);
		while(s <= e - 2 && crs(e-2, e-1) > crs(e-1, e)){
			pa[e-1] = pa[e];
			pb[e-1] = pb[e];
			e--;
		}
		e++;
	}
	lint query(lint x){
		int ts = s, te = e-1;
		while(ts != te){
			int tm = (ts + te) / 2;
			if(pa[tm] * x + pb[tm] > pa[tm+1] * x + pb[tm+1]) te = tm;
			else ts = tm+1;
		}
		return pa[ts] * x + pb[ts];
	}
}cht;

int main(){
	scanf("%d",&n);
	lint s1 = 0, s2 = 0;
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);	
		s1 += t;
		s2 += 1ll * i * t;
		a[i] = s1;
		b[i] = s2;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		cht.add(i-1, (i-1) * a[i-1] - b[i-1]);
		ret = max(ret, b[i] + cht.query(-a[i]));
	}
	cout << ret;
}