#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n, m;
struct Node{
	int x, y, i;
	
	inline operator < (const Node &node) const {
		return x < node.x; 
	}
}a[maxn];

char s[maxn];
int ans[maxn];
vector<int> v;
vector<Node> w[2];

void solve(vector<Node> a){
	sort(a.begin(), a.end());
	for(int i = 0;i < a.size();i++){
		if(a[i].y == 'L'){
			if(v.empty()) v.push_back(i);
			else{
				int j = v.back();v.pop_back();
				ans[a[i].i] = ans[a[j].i] = (a[i].x - a[j].x) / 2 + (a[j].y == 'L' ? a[j].x : 0);
			}
		}else{
			v.push_back(i);
		}
	}
	for(int I = v.size() - 1;I >= 1;I -= 2){
		int i = v[I], j = v[I - 1];
		if(a[j].y == 'L'){
			ans[a[i].i] = ans[a[j].i] = (a[j].x + m - a[i].x + m) / 2;
			continue;
		}
		ans[a[i].i] = ans[a[j].i] = (a[i].x - a[j].x) / 2 + (m - a[i].x);
	} 
	v.clear();
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		w[0].clear(), w[1].clear();
		for(int i = 1;i <= n;i++) scanf("%d", &a[i].x);
		for(int i = 1;i <= n;i++) scanf("%s", s), a[i].y = s[0], a[i].i = i, ans[i] = -1;
		for(int i = 1;i <= n;i++) w[a[i].x & 1].push_back(a[i]);
		solve(w[0]), solve(w[1]);
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts(""); 
	}
}