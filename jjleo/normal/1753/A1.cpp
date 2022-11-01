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
		if(n & 1){
			puts("-1");
			continue;
		}
		vector<pair<int, int> > v;
		for(int i = 1;i <= n;i += 2){
			if(a[i] == a[i + 1]) v.push_back({i, i + 1});
			else v.push_back({i, i}), v.push_back({i + 1, i + 1});
		}
		printf("%d\n", v.size());
		for(auto it : v) printf("%d %d\n", it.first, it.second);
	}
}