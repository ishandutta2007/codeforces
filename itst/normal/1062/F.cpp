#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7;
int s[_] , t[_] , num[_] , d[_] , N , M; vector < int > nxt[_];

void topo(){
	int lft = N; queue < int > q;
	for(int i = 1 ; i <= N ; ++i) if(!d[i]) q.push(i);
	while(!q.empty()){
		int t = q.front(); q.pop(); --lft;
		if(q.size() >= 2) num[t] = -1e9;
		else if(q.size() == 1){
			int s = q.front(); num[t] += lft - 1;
			for(auto p : nxt[s]) if(d[p] == 1) num[t] = -1e9;
		}else num[t] += lft;
		for(auto x : nxt[t]) if(!--d[x]) q.push(x);
	}
}

int main(){
	scanf("%d %d" , &N , &M);
	for(int i = 1 ; i <= M ; ++i){scanf("%d %d" , &s[i] , &t[i]); nxt[s[i]].push_back(t[i]); ++d[t[i]];}
	topo(); for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
	for(int i = 1 ; i <= M ; ++i){nxt[t[i]].push_back(s[i]); ++d[s[i]];}
	topo(); int ans = 0; for(int i = 1 ; i <= N ; ++i) ans += num[i] >= N - 2;
	printf("%d\n" , ans); return 0;
}