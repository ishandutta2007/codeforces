#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x;
int a[maxn], b[maxn], c[maxn];
int mx;

set<pair<int, int> > st;

inline bool check(int x){
	st.clear();
	for(int i = 1;i <= n;i++) b[i] = a[i];
	for(int i = 1;i <= n;i++) if(b[i]) st.insert({b[i], i});
	for(int i = 1;i <= n;i++){
		if(i - x - 1 > 0){
			if(b[c[i - x - 1]]) st.insert({b[c[i - x - 1]], c[i - x - 1]});
		}
		if(st.empty()) return false;
		pair<int, int> p = *st.rbegin();
		c[i] = p.second;
		b[p.second]--;
		st.erase(p);
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			a[x]++;
		}
		int l = 0, r = n - 2, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
}