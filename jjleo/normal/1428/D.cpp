#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], b[maxn];
bool tag[maxn];
vector<int> v[3];
vector<pair<int, int> > ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = n;i;i--){
		if(a[i] == 1) v[0].push_back(i);
		if(a[i] == 2) v[1].push_back(i);
		if(a[i] == 2){
			if(v[0].size() == 0) return printf("-1"), 0;
			tag[b[i] = v[0].back()] = true, v[0].pop_back();
		}
		if(a[i] == 3){
			if(v[2].size() == 0 && v[1].size() == 0 && v[0].size() == 0) return printf("-1"), 0;
			if(v[2].size()){
				b[i] = v[2].back(), v[2].pop_back();
			}else if(v[1].size()){
				b[i] = v[1].back(), v[1].pop_back();
			}else{
				b[i] = v[0].back(), v[0].pop_back();
			}
		}
		if(a[i] == 3) v[2].push_back(i);
	}
	for(int i = 1;i <= n;i++){
		if(!a[i] || tag[i]) continue;
		ans.push_back({i, i});
		if(a[i] == 2){
			ans.push_back({i, b[i]});
		}else if(a[i] == 3){
			ans.push_back({i, b[i]});
			//if(b[i] != i + 1) ans.push_back({i + 1, b[i]}); 
		}
	} 
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
}