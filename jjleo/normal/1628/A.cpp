#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
vector<int> v[maxn];
int a[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 0;i <= n;i++) v[i].clear();
		for(int i = n;i;i--) v[a[i]].push_back(i);
		vector<int> w;
		int last = 1;
		while(1){
			int mx = 0, id = 0;
			for(int i = 0;;i++){
				if(v[i].empty()) break;
				mx = max(mx, v[i].back());
				id = i + 1;
			}
			if(mx == 0) break;
			w.push_back(id);
			for(int i = last;i <= mx;i++) v[a[i]].pop_back();
			last = mx + 1;
		}
		for(int i = 1;i <= n - last + 1;i++) w.push_back(0);
		printf("%d\n", w.size());
		for(int i = 0;i < w.size();i++) printf("%d ", w[i]);puts("");
	}
}