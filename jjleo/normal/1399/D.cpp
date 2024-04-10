#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
char s[maxn];
vector<int> v[2];
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		v[0].clear(), v[1].clear();
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			int x = s[i] - '0';
			if(v[x ^ 1].empty()) v[x ^ 1].push_back(++cnt);
			ans[i] = v[x ^ 1].back();
			v[x ^ 1].pop_back();
			v[x].push_back(ans[i]);
		}
		printf("%d\n", cnt);
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
	}
}