#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
#define sz(v) ((int)(v).size())
using lint = long long;

int n, arr[MAXN];
lint x, a, y, b;
lint k;

lint trial(int n){
	vector<int> c(3);
	for(int i=1; i<=n; i++){
		if(i % a == 0 && i % b == 0) c[0]++;
		else if(i % a == 0) c[1]++;
		else if(i % b == 0) c[2]++;
	}
	lint ret = 0;
	for(int i=0; i<c[0]; i++){
		ret += (x + y) * arr[i] / 100;
	}
	for(int i=c[0]; i<c[0]+c[1]; i++){
		ret += x * arr[i] / 100;
	}
	for(int i=c[0]+c[1]; i<c[0]+c[1]+c[2]; i++){
		ret += y * arr[i] / 100;
	}
	return ret;
}

int main(){
	int q; cin >> q;
	while(q--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		sort(arr, arr + n);
		reverse(arr, arr + n);
		cin >> x >> a >> y >> b >> k;
		if(x < y) swap(x, y), swap(a, b);
		int s = 0, e = n;
		while(s != e){
			int m = (s+e)/2;
			if(trial(m) >= k) e = m;
			else s = m + 1;
		}
		if(trial(s) < k) puts("-1");
		else printf("%d\n", s);
	}
}