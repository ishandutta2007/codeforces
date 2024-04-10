#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n[5], m;
ll a[5][maxn];
multiset<ll> st;
vector<int> v[5][maxn];
int x, y;

int main(){
	for(int i = 1;i <= 4;i++) scanf("%d", &n[i]);
	for(int i = 1;i <= 4;i++) for(int j = 1;j <= n[i];j++) scanf("%lld", &a[i][j]);
	for(int i = 2;i <= 4;i++){
		scanf("%d", &m);
		while(m--){
			scanf("%d%d", &x, &y);
			v[i][y].push_back(x);
		}
	}
	for(int i = 2;i <= 4;i++){
		st.clear();
		for(int j = 1;j <= n[i - 1];j++) st.insert(a[i - 1][j]);
		for(int j = 1;j <= n[i];j++){
			for(int k = 0;k < v[i][j].size();k++){
				st.erase(st.find(a[i - 1][v[i][j][k]]));
			}
			if(st.empty()) a[i][j] = 1e18;
			else a[i][j] += *st.begin();
			for(int k = 0;k < v[i][j].size();k++){
				st.insert(a[i - 1][v[i][j][k]]);
			}
		}
	}
	ll ans = 1e18;
	for(int i = 1;i <= n[4];i++) ans = min(ans, a[4][i]);
	printf("%lld", ans == 1e18 ? -1 : ans);
}