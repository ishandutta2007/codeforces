#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int q, n;
char s[maxn], t[maxn];

int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%d%s%s", &n, s + 1, t + 1);
		if(s[1] != t[1] || s[n] != t[n]){
			puts("-1");
			continue; 
		}
		vector<pair<int, int> > v, w;
		int st, len = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				if(len == 0) len = 1, st = i;
				else len++;
			}else{
				if(len) v.push_back({st, len});
				len = 0;
			}
		}
		if(len) v.push_back({st, len});
		len = 0;
		for(int i = 1;i <= n;i++){
			if(t[i] == '1'){
				if(len == 0) len = 1, st = i;
				else len++;
			}else{
				if(len) w.push_back({st, len});
				len = 0;
			}
		}
		if(len) w.push_back({st, len});
		if(v.size() != w.size()){
			puts("-1");
			continue; 
		}
		long long ans = 0;
		for(int i = 0;i < v.size();i++){
			ans += abs(v[i].second - w[i].second);
			int l = v[i].first, r = v[i].first + v[i].second - 1;
			int L = w[i].first, R = w[i].first + w[i].second - 1;
			if(!(l <= L && R <= r || L <= l && r <= R)){
				ans += 2 * min(abs(l - L), abs(r - R));
			}
		}
		printf("%lld\n", ans);
	}
}