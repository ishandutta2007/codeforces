#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int ans = 0;
	vector<pair<int, int> > v; 
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			v.clear();
			ans++;
		}else{
			vector<pair<int, int> > w;
			for(int j = 0;j < v.size();j++){
				int x = __gcd(v[j].first, a[i]);
				if(w.empty() || x != w.back().first) w.push_back({x, v[j].second});
			}
			if(w.empty() || a[i] != w.back().first) w.push_back({a[i], i});
			for(int j = 0;j < w.size();j++){
				int l = w[j].second;
				int r = j + 1 < w.size() ? w[j + 1].second - 1 : i;
				if(i - r + 1 <= w[j].first && w[j].first <= i - l + 1){
					w.clear();
					ans++;
					break;
				}
			}
			swap(v, w);
		} 
		printf("%d ", ans);
	}
}