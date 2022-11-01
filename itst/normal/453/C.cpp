#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 3; vector < int > nxt[_]; int N , M , fa[_] , val[_] , fvl[_];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

vector < int > pot;
void dfs(int x , int p){
	pot.push_back(x); val[x] ^= 1; for(auto t : nxt[x]) if(t != p){dfs(t , x); val[x] ^= 1; pot.push_back(x);}
	if(val[x]) if(!p) pot.pop_back(); else{pot.push_back(p); pot.push_back(x); val[p] ^= 1;}
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; if(find(p) != find(q)){nxt[p].push_back(q); nxt[q].push_back(p); fa[find(p)] = find(q);}}
	for(int i = 1 ; i <= N ; ++i){cin >> val[i]; fvl[find(i)] |= val[i];}
	int cnt = 0; for(int i = 1 ; i <= N ; ++i) cnt += fa[i] == i && fvl[i];
	if(cnt >= 2) puts("-1"); else if(cnt == 0) puts("0");
	else{int rt = 1; while(!fvl[rt]){++rt;} dfs(rt , 0); cout << pot.size() << endl; for(auto t : pot) cout << t << ' ';}
	return 0;
}