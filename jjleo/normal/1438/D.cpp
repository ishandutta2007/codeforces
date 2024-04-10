#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int x, y, z;
};
vector<Node> ans;

int n, x;
vector<int> v;
int a[maxn];
vector<int> w[maxn];
vector<int> b; 

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v.push_back(a[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++) w[lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1].push_back(i);
	for(int i = 1;i <= v.size();i++){
		if(w[i].size() & 1){
			b.push_back(w[i].back()), w[i].pop_back();
		}
	}
	if(b.empty()){
		int x = w[1].back();
		for(int i = 2;i <= v.size();i++){
			for(int j = 0;j < w[i].size();j += 2){
				ans.push_back((Node){x, w[i][j], w[i][j + 1]});
			}
		}
	}else{
		int x = b.size();
		for(int i = 0;i + 2 < b.size();i += 2){
			ans.push_back((Node){b[i], b[i + 1], b[i + 2]});
			a[b[i]] = a[b[i + 1]] = a[b[i + 2]] = a[b[i]] ^ a[b[i + 1]] ^ a[b[i + 2]];
		}
		if(!(b.size() & 1) && a[b.back()] != a[b[b.size() - 2]]) return printf("NO"), 0;
		for(int i = 0;i + 2 < b.size();i += 2) ans.push_back((Node){b[i], b[i + 1], b.back()});
		x = b.back();
		for(int i = 2;i <= v.size();i++){
			for(int j = 0;j < w[i].size();j += 2){
				ans.push_back((Node){x, w[i][j], w[i][j + 1]});
			}
		}
	}
	puts("YES");
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
}