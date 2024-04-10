#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;
int a[maxn];
multiset<int> st;
vector<pair<int, int> > ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), n <<= 1;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool suc = false;
		for(int j = 1;j <= n;j++){
			st.clear(), ans.clear();
			for(int i = 1;i <= n;i++) if(i ^ j) st.insert(a[i]);
			x = *st.rbegin(), st.erase(st.find(x));
			ans.push_back({x, a[j]});
			x = max(x, a[j]);
			bool tag = false;
			for(int i = 1;i <= n - 2;i += 2){
				int X = *st.rbegin();
				st.erase(st.find(X));
				if(st.find(x - X) == st.end()){
					tag = true;
					break;
				}
				ans.push_back({X, x - X});
				st.erase(st.find(x - X));
				x = X;
			}
			if(tag) continue;
			suc = true;
			puts("YES");
			printf("%d\n", ans[0].first + ans[0].second);
			for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
			break;
		}
		if(!suc){
			puts("NO");
			continue;
		}
	}
}