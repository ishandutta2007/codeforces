#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
bool tag[maxn];
vector<pair<int, int> > v;
int x, y;
vector<int> a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n * 2;i++) tag[i] = false;
		v.clear(), a.clear();
		for(int i = 1;i <= k;i++){
			scanf("%d%d", &x ,&y);
			if(x > y) swap(x, y);
			tag[x] = tag[y] = true, v.push_back({x, y});
		}
		for(int i = 1;i <= n * 2;i++) if(!tag[i]) a.push_back(i);
		for(int i = 0;i + a.size() / 2 < a.size();i++) v.push_back({a[i], a[i + a.size() / 2]});
		int ans = 0;
		for(int i = 0;i < v.size();i++){
			//printf("%d %d--\n", v[i].first, v[i].second);
			for(int j = 0;j < v.size();j++){
				ans += v[i].first < v[j].first && v[j].first < v[i].second && v[i].second < v[j].second;
			}
		}
		printf("%d\n", ans);
	}
}