#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m; 
long long L, R;
vector<int> a[maxn], b[maxn];
multiset<pair<int, int> > st;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= max(n, m);i++){
		for(int j = 1;i * j <= max(n, m);j++){
			if(i * j <= n) a[i * j].push_back(i);
			if(i * j <= m) b[i * j].push_back(i);
		}
	}
	scanf("%lld%lld", &L, &R);
	int l = m + 1, r = m;
	for(int i = 1;i <= n;i++){
		while(l > (L + i - 1) / i){
			l--;
			for(int j = 0;j < b[l].size();j++) st.insert({b[l][j], l});
		}
		while(r > R / i){
			for(int j = 0;j < b[r].size();j++) st.erase(st.find({b[r][j], r}));
			r--;
		}
		bool tag = false;
		for(int j = 0;j < a[i].size();j++){
			multiset<pair<int, int> >::iterator it = st.upper_bound({a[i][j], 1e9});//debugsecond0first=a[i][j] 
			if(it == st.end()) continue;
			int x = it->first, y = it->second;
			if(1ll * i / a[i][j] * x <= n){
				tag = true, printf("%d %d %d %d\n", i, y, i / a[i][j] * x, 1ll * i * y / (i / a[i][j] * x));
				break;
			}
		}
		if(!tag) puts("-1");
	}
}