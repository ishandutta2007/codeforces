#include<bits/stdc++.h>
using namespace std;

const int _ = 803; int Case , N , M;
char Map[23][23]; int S[_] , T[_] , ce; 
#define id(i , j) (((i) - 1) * M + (j))
#define pii pair < int , int >
pii trans(int x){return make_pair((x - 1) / M + 1 , (x - 1) % M + 1);}
bool black(int x){pii t = trans(x); return (1 + t.first + t.second) & 1;}

bool ch[_] , in1[_] , in2[_];
vector < int > nxt[_]; int pre[_] , dst[_]; queue < int > q;

vector < int > ed[_]; int in[_] , dfn[_] , low[_] , stk[_] , top , ts , cnt;
void tarjan(int x , int p){
	dfn[x] = low[x] = ++ts; stk[++top] = x;
	for(auto t : ed[x]){
		if(t == p) continue;
		if(!dfn[t]){
			tarjan(t , x); low[x] = min(low[x] , low[t]);
			if(low[t] > dfn[x]){++cnt; do in[stk[top]] = cnt; while(stk[top--] != t);}
		}else low[x] = min(low[x] , dfn[t]);
	}
}

void link1(){
	for(int i = 1 ; i <= N * M ; ++i) ed[i].clear();
	for(int i = 1 ; i <= ce ; ++i){in1[i] = 0; if(!ch[i]){ed[S[i]].push_back(T[i]); ed[T[i]].push_back(S[i]);}}
	memset(dfn , 0 , sizeof(int) * (N * M + 1)); ts = cnt = 0; tarjan(1 , 0); ++cnt; while(top) in[stk[top--]] = cnt;

	static int id[_] , to[_];
	for(int i = 1 ; i <= ce ; ++i)
		if(!ch[i] && in[S[i]] == in[T[i]]) in1[i] = 1;
		else if(!ch[i]){id[min(in[S[i]] , in[T[i]])] = i; to[min(in[S[i]] , in[T[i]])] = max(in[S[i]] , in[T[i]]);}
	for(int i = 1 ; i <= ce ; ++i)
		if(ch[i]){
			int p = in[S[i]] , q = in[T[i]]; if(p > q) swap(p , q);
			while(p != q){nxt[i].push_back(id[p]); p = to[p]; if(p > q) swap(p , q);}
		}
}

bool link2(bool flg = 0){
	static int du[_]; memset(du , 0 , sizeof(du)); du[1] = 1e9;
	for(int i = 1 ; i <= ce ; ++i){in2[i] = 0; if(!ch[i]) ++du[black(S[i]) ? S[i] : T[i]];}
	if(flg){
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 1 + !(i & 1); j <= M ; j += 2)
				if(Map[i][j] == 'O' && du[id(i , j)] <= 1) return 0;
		return 1;
	}
	for(int i = 1 ; i <= ce ; ++i)
		if(!ch[i])
			if(du[black(S[i]) ? S[i] : T[i]] > 2) in2[i] = 1;
			else for(int j = 1 ; j <= ce ; ++j) if(ch[j] && (black(S[i]) ? S[i] : T[i]) == (black(S[j]) ? S[j] : T[j])) nxt[i].push_back(j);
	return 1;
}

int main(){
	for(cin >> Case ; Case ; --Case){
		cin >> N >> M; int num = ce = 0; for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j){cin >> Map[i][j]; num += Map[i][j] == 'O';}
		for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j < M ; ++j) if(Map[i][j] == 'O' && Map[i][j + 1] == 'O'){S[++ce] = id(i , j); T[ce] = id(i , j + 1);}
		for(int i = 1 ; i < N ; ++i) for(int j = 1 ; j <= M ; ++j) if(Map[i][j] == 'O' && Map[i + 1][j] == 'O'){S[++ce] = id(i , j); T[ce] = id(i + 1 , j);}

		memset(ch , 0 , sizeof(ch)); bool flg = !link2(1);
		for(int i = 1 ; !flg && i <= ce - num + 1 ; ++i){
			for(int i = 1 ; i <= ce ; ++i){dst[i] = -1; nxt[i].clear();}
			link1(); link2(); while(!q.empty()) q.pop();
			for(int i = 1 ; i <= ce ; ++i) if(in1[i]){q.push(i); dst[i] = 0; pre[i] = 0;}
			int id = 0;
			while(!q.empty()){
				int t = q.front(); q.pop(); if(in2[t]){id = t; break;}
				for(auto p : nxt[t]) if(!~dst[p]){dst[p] = dst[t] + 1; pre[p] = t; q.push(p);}
			}
			if(!id) flg = 1; else while(id){ch[id] ^= 1; id = pre[id];}
		}
		
		if(flg) cout << "NO" << endl;
		else{
			cout << "YES" << endl; static char ans[43][43]; memset(ans , ' ' , sizeof(ans));
			for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j) ans[2 * i - 1][2 * j - 1] = Map[i][j];
			for(int i = 1 ; i <= ce ; ++i)
				if(!ch[i]){
					pii l = trans(S[i]); bool flg = T[i] - S[i] == 1;
					ans[2 * l.first - flg][2 * l.second - !flg] = 'O';
				}
			for(int i = 1 ; i <= 2 * N - 1 ; ++i , cout << endl) for(int j = 1 ; j <= 2 * M - 1 ; ++j) cout << ans[i][j];
		}
	}
	return 0;
}