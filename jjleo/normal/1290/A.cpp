#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		vector<int> v;
		for(int i = 0;n - (m - 1) + i <= n;i++) v.push_back(max(a[1 + i], a[n - (m - 1) + i]));
		if(k >= v.size()){
			printf("%d\n", *max_element(v.begin(), v.end()));
			continue;
		}
		multiset<int> st;
		int ans = 0;
		for(int i = 0;i < v.size();i++){
			st.insert(v[i]);
			if(i - ((int)v.size() - k) >= 0) st.erase(st.find(v[i - ((int)v.size() - k)]));
			if(st.size() >= (int)v.size() - k) ans = max(ans, *st.begin());
		}
		printf("%d\n", ans);
	}
}