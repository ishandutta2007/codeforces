#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

ll f[maxn];

int n, m;
int a[maxn], b[maxn], p[maxn];
ll ans = 1e18;

inline void add(int x, ll y){
	for(;x <= m;x += x & -x) f[x] += y;
}

inline ll query(int x){
	ll sum = 0;
	for(;x;x -= x & -x) sum += f[x];
	return sum;
}


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &p[i]);
	scanf("%d", &m), ++m;
	for(int i = 2;i <= m;i++) scanf("%d", &b[i]);
	add(2, 1e18);
	for(int i = 1;i <= n;i++){
		int x = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		if(b[x] != a[i]){
			add(1, p[i]), add(x, -p[i]);
			add(x, min(0, p[i]));
		}else{
			//printf("%d %lld %lld---\n", x, query(x - 1), query(x));
			ll y = min(query(x - 1), query(x) + min(0, p[i])) - query(x);//debug:j min(0 
			add(x, y), add(x + 1, -y);
			add(1, p[i]), add(x, -p[i]);
			add(x + 1, min(0, p[i]));
		}
			
	}
	if(query(m) >= 1e15) printf("NO");
	else printf("YES\n%lld", query(m));//
}