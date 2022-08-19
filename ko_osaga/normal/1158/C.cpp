#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 500005;
const int mod = 1e9 + 7;

int nxt[MAXN], a[MAXN];
vector<int> gph[MAXN];
int pos, n;

void dfs(int x){
	a[x] = pos--;
	for(auto &i : gph[x]) dfs(i);
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		nxt[0] = n + 1;
		{
			vector<int> stk = {0};
			for(int i=1; i<=n; i++){
				scanf("%d",&nxt[i]);
				if(nxt[i] == -1){
					while(!stk.empty() && nxt[stk.back()] <= i) stk.pop_back();
					nxt[i] = nxt[stk.back()];
					stk.push_back(i);
				}
				else{
					while(!stk.empty() && nxt[stk.back()] <= nxt[i]) stk.pop_back();
					stk.push_back(i);
				}
			}
		}
		for(int i=1; i<=n; i++) gph[nxt[i]].push_back(i);
		pos = n + 1;
		dfs(n + 1);
		vector<int> stk = {n + 1};
		bool good = 1;
		for(int i=n; i; i--){
			while(!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
			if(stk.empty() || stk.back() != nxt[i]){
				good = 0;
				break;
			}
			stk.push_back(i);
		}
		for(int i=1; i<=n+1; i++) gph[i].clear();
		if(!good){
			puts("-1");
			continue;
		}
		for(int i=1; i<=n; i++) printf("%d ", a[i]);
		puts("");
	}
}