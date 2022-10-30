#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int p[maxn];

inline void add(int x, int y){
	for(;x <= n;x += x & -x) p[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += p[x];
	return sum;
}

int t;
int a[maxn], l[maxn], r[maxn];
vector<int> ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]), p[i] = 0;
			l[i] = i == 1 ? n : i - 1;
			r[i] = i == n ? 1 : i + 1;
		}
		for(int i = 1;i <= n;i++) add(i, __gcd(a[i], a[l[i]]) == 1);
		ans.clear();
		int x = 2;
		for(int i = 1;i <= n;i++){
			if(query(n) - query(x - 1) != 0){
				int L = x, R = n, mid;
				while(L < R){
					mid = L + R >> 1;
					if(query(mid) - query(x - 1)) R = mid;
					else L = mid + 1;
				}
				ans.push_back(x = L);
				add(x, -1);
				l[r[x]] = l[x], r[l[x]] = r[x];
				if(__gcd(a[x], a[r[x]]) == 1) add(r[x], -1);
				if(__gcd(a[l[x]], a[r[x]]) == 1) add(r[x], 1);
				x = r[r[x]];
			}else{
				if(query(x - 1) == 0) break;
				int L = 1, R = x - 1, mid;
				while(L < R){
					mid = L + R >> 1;
					if(query(mid)) R = mid;
					else L = mid + 1;
				}
				ans.push_back(x = L);
				add(x, -1);
				l[r[x]] = l[x], r[l[x]] = r[x];
				if(__gcd(a[x], a[r[x]]) == 1) add(r[x], -1);
				if(__gcd(a[l[x]], a[r[x]]) == 1) add(r[x], 1);
				x = r[r[x]];			
			}
			
		}
		printf("%d", ans.size());
		for(int i = 0;i < ans.size();i++) printf(" %d", ans[i]);puts("");
	}
}