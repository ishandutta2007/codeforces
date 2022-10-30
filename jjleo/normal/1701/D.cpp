#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t, n, x;
vector<pair<int, int> > v[maxn];
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			int l = 1, r = n, mid;
			while(l < r){
				mid = (l + r >> 1) + 1;
				if(i / mid >= x) l = mid;
				else r = mid - 1;
			}
			int R = l;
			l = 1, r = n, mid;
			while(l < r){
				mid = l + r >> 1;
				if(i / mid > x) l = mid + 1;
				else r = mid;
			}
			int L = l;
			v[L].push_back({R, i});
		}
		set<pair<int, int> > st;
		for(int i = 1;i <= n;i++){
			for(auto j : v[i]) st.insert(j);
			assert(!st.empty());
			a[st.begin()->second] = i;
			st.erase(st.begin());
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}