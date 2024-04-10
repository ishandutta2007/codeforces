#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 7;
int head[_] , s[_] , t[_] , fa[_] , cntEd , N , K , M;
vector < int > nxt[_]; int s1[_] , t1[_] , w[_]; bool in[_];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int pre[_] , val[_] , dep[_];
void dfs(int x , int p){pre[x] = p; dep[x] = dep[p] + 1; for(auto t : nxt[x]) if(t != p) dfs(t , x);}

int main(){
	ios::sync_with_stdio(0); cin >> N >> K >> M;
	for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= K ; ++i){
		cin >> s[i] >> t[i]; fa[find(t[i])] = find(s[i]);
		nxt[s[i]].push_back(t[i]); nxt[t[i]].push_back(s[i]);
	}
	for(int i = 1 ; i <= M ; ++i){
		cin >> s1[i] >> t1[i] >> w[i];
		if(in[i] = find(s1[i]) != find(t1[i])){
			fa[find(s1[i])] = find(t1[i]); nxt[s1[i]].push_back(t1[i]); nxt[t1[i]].push_back(s1[i]);
		}
	}
	dfs(1 , 0); for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= M ; ++i)
		if(!in[i]){
			int p = find(s1[i]) , q = find(t1[i]);
			while(p != q){
				if(dep[p] < dep[q]) swap(p , q);
				val[p] = w[i]; p = find(fa[p] = pre[p]);
			}
		}
	long long sum = 0;
	for(int i = 1 ; i <= K ; ++i){
		int x = pre[t[i]] == s[i] ? t[i] : s[i]; sum += val[x];
		if(!val[x]){puts("-1"); return 0;}
	}
	cout << sum; return 0;
}