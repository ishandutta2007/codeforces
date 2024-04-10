#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int q;
int n;
char s[maxn], t[maxn];
vector<int> v[26];

int a[maxn];
inline void add(int x, int y){
	for(;x <= n;x += x & -x) a[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}


int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%d%s%s", &n, s + 1, t + 1);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 0;i < 26;i++) v[i].clear();
		for(int i = n;i;i--) v[s[i] - 'a'].push_back(i);
		long long ans = 1e18, sum = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < t[i] - 'a';j++){
				while(!v[j].empty() && v[j].back() + query(v[j].back()) < i) v[j].pop_back();
				if(v[j].empty()) continue;
				ans = min(ans, sum + v[j].back() + query(v[j].back()) - i);
			}
			int j = t[i] - 'a';
			while(!v[j].empty() && v[j].back() + query(v[j].back()) < i) v[j].pop_back();
			if(v[j].empty()) break;
			sum += v[j].back() + query(v[j].back()) - i;
			add(1, 1), add(v[j].back(), -1);
			v[j].pop_back();
		}
		if(ans == 1e18) puts("-1");
		else printf("%lld\n", ans);
	}
}