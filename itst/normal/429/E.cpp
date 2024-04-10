#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
int N , lsh[_] , s[_] , t[_] , col[_] , sum[_];
set < int > nxt[_];

void dfs(int x){
	while(!nxt[x].empty()){
		int id = *nxt[x].begin(); nxt[x].erase(id);
		nxt[s[id] + t[id] - x].erase(id); dfs(s[id] + t[id] - x);
		col[id] = x == s[id];
	}
}

int main(){
	cin >> N; int cnt = 0;
	for(int i = 1 ; i <= N ; ++i){cin >> s[i] >> t[i]; lsh[++cnt] = s[i]; lsh[++cnt] = ++t[i];}
	sort(lsh + 1 , lsh + cnt + 1); cnt = unique(lsh + 1 , lsh + cnt + 1) - lsh;
	for(int i = 1 ; i <= N ; ++i){
		s[i] = lower_bound(lsh + 1 , lsh + cnt , s[i]) - lsh;
		t[i] = lower_bound(lsh + 1 , lsh + cnt , t[i]) - lsh;
		if(s[i] > t[i]) swap(s[i] , t[i]);
		nxt[s[i]].insert(i); nxt[t[i]].insert(i); ++sum[s[i]]; --sum[t[i]];
	}
	int tmp = N;
	for(int i = 2 ; i <= cnt ; ++i){
		sum[i] += sum[i - 1];
		if(sum[i] & 1){nxt[i].insert(++tmp); nxt[i + 1].insert(tmp); s[tmp] = i; t[tmp] = i + 1;}
	}
	for(int i = 1 ; i <= cnt ; ++i) if(nxt[i].size()) dfs(i);
	for(int i = 1 ; i <= N ; ++i) printf("%d " , col[i]);
	return 0;
}