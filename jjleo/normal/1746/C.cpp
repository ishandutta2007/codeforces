#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		vector<pair<int, int> > v;
		for(int i = 2;i <= n;i++) v.push_back({a[i] - a[i - 1], i});
		sort(v.begin(), v.end());
		for(int i = 1;i <= n;i++) a[i] = 1;
		for(int i = 0;i < v.size();i++) a[n - i] = v[i].second;
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}