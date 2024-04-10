#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; vector < int > nxt1[_] , nxt2[_]; int N , M;
int mn1[_];
int search1(int p){
	if(mn1[p]) return mn1[p];
	mn1[p] = 1e9; for(auto t : nxt1[p]){mn1[p] = min(mn1[p] , t); mn1[p] = min(mn1[p] , search1(t));}
	return mn1[p];
}

bool vis[_] , ins[_];
bool dfs(int x){
	if(ins[x]) return 1;
	if(vis[x]) return 0;
	ins[x] = vis[x] = 1; for(auto t : nxt1[x]) if(dfs(t)) return 1;
	ins[x] = 0; return 0;
}

int mn2[_];
int search2(int p){
	if(mn2[p]) return mn2[p];
	mn2[p] = 1e9; for(auto t : nxt2[p]){mn2[p] = min(mn2[p] , t); mn2[p] = min(mn2[p] , search2(t));}
	return mn2[p];
}

int main(){
	cin >> N >> M; for(int i = 1 ; i <= M ; ++i){int j , k; cin >> j >> k; nxt1[j].push_back(k); nxt2[k].push_back(j);}
	int cnt = 0; string ans;
	for(int i = 1 ; i <= N ; ++i){
		if(!vis[i] && dfs(i)){cout << -1; return 0;}
		int t = min(search2(i) , search1(i));
		if(t > i){++cnt; ans.push_back('A');}
		else ans.push_back('E');
	}
	cout << cnt << endl << ans << endl;
	
	return 0;
}