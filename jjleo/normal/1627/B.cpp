#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		vector<int> v;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) v.push_back(max(i - 1, n - i) + max(j - 1, m - j));
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
	}
}