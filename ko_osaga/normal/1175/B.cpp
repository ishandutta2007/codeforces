#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;
using pi = pair<int, int>;
const lint inf = 1e11;

int n;
string instr[MAXN];
int a[MAXN];
int mtch[MAXN];

lint dfs(int x, int y){
	if(x > y) return 0;
	if(instr[x] == "add") return min(dfs(x + 1, y) + 1, inf);
	auto t = dfs(x + 1, mtch[x] - 1) * a[x];
	t += dfs(mtch[x] + 1, y);
	t = min(t, inf);
	return t;
}

int main(){
	cin >> n;
	stack<int> stk;
	for(int i=1; i<=n; i++){
		cin >> instr[i];
		if(instr[i] == "for"){
			cin >> a[i];
			stk.push(i);
		}
		if(instr[i] == "end"){
			mtch[stk.top()] = i;
			stk.pop();
		}
	}
	auto ans = dfs(1, n);
	if(ans >> 32) puts("OVERFLOW!!!");
	else cout << ans;
}