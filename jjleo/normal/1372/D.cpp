#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

/*int n;
set<pair<long long, pair<long long, int> > > st;
int l[maxn], r[maxn];
long long a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	if(n == 1) return printf("%lld", a[1]), 0;
	for(int i = 1;i <= n;i++){
		if(i == 1) l[i] = n;
		else l[i] = i - 1;
		if(i == n) r[i] = 1;
		else r[i] = i + 1;
		st.insert({a[i], {-(a[l[i]] + a[r[i]]), i}}); 
	}
	for(int i = n;i > 1;i -= 2){
		int x = (st.begin())->second.second;
		st.erase(st.begin());
		//printf("%d %d %d--\n", x, l[x], r[x]);
		long long y = a[l[x]] + a[r[x]];
		if(i == 3) return printf("%lld", y), 0;
		int j = l[x], k = r[x];
		st.erase({a[j], {-(a[l[j]] + a[r[j]]), j}});
		st.erase({a[k], {-(a[l[k]] + a[r[k]]), k}});
		j = l[x] = l[l[x]], k = r[x] = r[r[x]];
		
		
		st.erase({a[j], {-(a[l[j]] + a[r[j]]), j}});
		st.erase({a[k], {-(a[l[k]] + a[r[k]]), k}});
		r[l[x]] = x, l[r[x]] = x;
		st.insert({a[x] = y, {-(a[l[x]] + a[r[x]]), x}});
		st.insert({a[j], {-(a[l[j]] + a[r[j]]), j}});
		st.insert({a[k], {-(a[l[k]] + a[r[k]]), k}});
		
	}
}*/

int n, x, a[maxn];
long long sum, f[2];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
	if(n == 1) return printf("%d", a[1]), 0;
	for(int i = 3;i < n;i += 2){
		f[1] = min(f[0], f[1]) + a[i + 1];
		f[0] += a[i];
	}
	long long ans = sum - a[1] - min(f[0], f[1]);
	f[0] = f[1] = 0;
	for(int i = 2;i <= n;i += 2){
		f[1] = min(f[0], f[1]) + a[i + 1];	
		f[0] += a[i];
	}
	printf("%lld", max(ans, sum - min(f[0], f[1])));
}