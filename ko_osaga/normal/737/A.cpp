#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, k, t;
int a[200005];

lint trial(lint x){
	lint ret = 0;
	for(int i=0; i<k; i++){
		if(a[i] > x) return 1e12;
		lint k = x - a[i];
		k = min(k, 1ll * a[i]);
		ret += 2 * a[i] - k;
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&k);
	scanf("%d %d",&a[k],&t);
	vector<pi> v;
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		v.push_back(pi(a, b));
	}
	for(int i=0; i<k; i++) scanf("%d",&a[i]);
	k++; sort(a, a+k);
	for(int i=k-1; i; i--) a[i] -= a[i-1];
	lint s = 0, e = 1e10;
	while(s != e){
		lint m = (s+e)/2;
		if(trial(m) <= t) e = m;
		else s = m+1;
	}
	if(trial(s) > t){
		puts("-1");
		return 0;
	}
	int ret = 2e9 + 22;
	for(auto &i : v){
		if(i.second >= s) ret = min(ret, i.first);
	}
	if(ret > 2e9 + 2){
		ret = -1;
	}
	cout << ret;
}