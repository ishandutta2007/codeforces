#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		vector<int> w;
		for(int i = 1;i <= n;i++) if(a[i]) w.push_back(i);
		if(w.size() & 1){
			puts("-1");
			continue;
		}
		if(w.empty()){
			printf("1\n1 %d\n", n);
			continue;
		}
		vector<pair<int, int> > v;
		if(w[0] > 1) v.push_back({1, w[0] - 1});
		for(int i = 0;i < w.size();i += 2){
			if(i && w[i - 1] + 1 != w[i]) v.push_back({w[i - 1] + 1, w[i] - 1});
			if(a[w[i]] != a[w[i + 1]]){
				v.push_back({w[i], w[i + 1] - 1});
				v.push_back({w[i + 1], w[i + 1]});
			}else{
				if((w[i + 1] - w[i]) & 1) v.push_back({w[i], w[i + 1]});
				else v.push_back({w[i], w[i]}), v.push_back({w[i] + 1, w[i + 1]});
			}
		}
		if(w.back() < n) v.push_back({w.back() + 1, n});
		printf("%d\n", v.size());
		for(auto it : v) printf("%d %d\n", it.first, it.second);
	}
}