#include<bits/stdc++.h>
using namespace std;

namespace flow{
	const int __ = 1e5 + 7 , _ = 1e4 + 7;
	struct Edge{int end , upEd , f;}Ed[__];
	int cur[_] , head[_] , dep[_] , cntEd , S , T;
	queue < int > q;

	void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
	void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , 0);}
	
	bool bfs(){
		while(!q.empty()) q.pop(); q.push(S);
		memset(dep , 0 , sizeof(int) * (T + 1)); dep[S] = 1;
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(!dep[Ed[i].end] && Ed[i].f){
					dep[Ed[i].end] = dep[t] + 1; q.push(Ed[i].end);
					if(Ed[i].end == T){
						memcpy(cur , head , sizeof(int) * (T + 1));
						return 1;
					}
				}
		}
		return 0;
	}
	
	int dfs(int x , int mn){
		if(x == T) return mn;
		int sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
				int t = dfs(Ed[i].end , min(Ed[i].f , mn - sum));
				sum += t; Ed[i].f -= t; Ed[i ^ 1].f += t;
				if(sum == mn) break;
			}
		return sum;
	}

	int Dinic(int s , int t){S = s; T = t; int sum = 0; while(bfs()) sum += dfs(S , 1e9); return sum;}
	void clear(){memset(head , 0 , sizeof(int) * (T + 1)); cntEd = 1;}
}using namespace flow;

#define PII pair < int , int >
#define sz(x) (int)x.size()
const int A = 503; deque < int > p1[A][A] , p2[A] , p3[A] , p4;
int id[A][A] , dir[A][A] , N , mxd[A] , ans[A]; bool vis[A]; PII to[A * 4];

int main(){
	scanf("%d" , &N); vector < int > len;
	for(int i = 1 ; i <= N ; ++i){
		string D , L; cin >> D >> L; int p = atoi(D.c_str()) , q = atoi(L.c_str());
		if(D == "?" && L == "?") p4.push_back(i);
		else if(D == "?"){p3[q].push_back(i); vis[q] = 1;}
		else if(L == "?"){p2[p].push_back(i); mxd[0] = max(mxd[0] , p);}
		else{p1[q][p].push_back(i); vis[q] = 1; mxd[q] = max(mxd[q] , p);}
	}
	for(int i = 1 ; i <= N ; ++i) if(vis[i]) len.push_back(i);
	if(len.empty()) len.push_back(1);
	int allmx = 0; for(int i = 0 ; i <= N ; ++i) allmx = max(allmx , mxd[i]);
	
	for(auto t : len){
		int pre = mxd[t] , cnt = 0; mxd[t] = max(mxd[t] , mxd[0]); clear();

		//add LD
		for(auto p : len)
			for(int q = 0 ; q <= mxd[p] && cnt - sz(len) <= N ; ++q)
				if((to[id[p][q] = ++cnt] = PII(p , q)).second)
					addE(0 , cnt , sz(p1[p][q]));
		
		if(cnt - sz(len) > N){mxd[t] = pre; continue;}
		
		//add ??
		addE(0 , ++cnt , p4.size()); for(auto p : len) for(int q = 0 ; q <= mxd[p] ; ++q) addE(cnt , id[p][q] , 1e9);

		//add L?
		for(auto p : len){
			addE(0 , ++cnt , sz(p3[p]));
			for(int q = 0 ; q <= mxd[p] ; ++q) addE(cnt , id[p][q] , 1e9);
		}

		//add ?D
		for(int i = 0 ; i <= allmx ; ++i) addE(0 , ++cnt , sz(p2[i]));
		for(auto p : len) for(int q = 0 ; q <= mxd[p] ; ++q) addE(cnt - allmx + q , id[p][q] , 1e9);
		
		//add to T
		++cnt; int num = 0;
		for(auto p : len){
			for(int q = 1 ; q <= mxd[p] ; ++num , ++q) addE(id[p][q] , cnt , 1);
			int val = sz(p1[p][0]) ? (sz(p1[p][0]) % p ? p - sz(p1[p][0]) % p : 0) : p;
			num += val; addE(id[p][0] , cnt , val);
		}

		if(Dinic(0 , cnt) != num){mxd[t] = pre; continue;}

		//find dir LD
		cnt = 0;
		for(auto p : len){
			for(int q = 1 ; q <= mxd[p] ; ++q)
				for(int i = head[id[p][q]] ; i ; i = Ed[i].upEd)
					if(!Ed[i].end && Ed[i].f){dir[p][q] = p1[p][q].front(); p1[p][q].pop_front();}
			cnt += mxd[p] + 1;
		}
		
		//find dir ??
		for(int i = head[++cnt] ; i ; i = Ed[i].upEd)
			while(Ed[i].end && Ed[i ^ 1].f--){
				PII p = to[Ed[i].end]; int id = p4.front(); p4.pop_front();
				p.second ? (void)(dir[p.first][p.second] = id) : p1[p.first][0].push_back(id);
			}
		
		//find dir L?
		for(auto q : len)
			for(int i = head[++cnt] ; i ; i = Ed[i].upEd)
				while(Ed[i].end && Ed[i ^ 1].f--){
					PII p = to[Ed[i].end]; int id = p3[q].front(); p3[q].pop_front();
					p.second ? (void)(dir[p.first][p.second] = id) : p1[p.first][0].push_back(id);
				}

		//find dir ?D
		for(int q = 0 ; q <= allmx ; ++q)
			for(int i = head[++cnt] ; i ; i = Ed[i].upEd)
				while(Ed[i].end && Ed[i ^ 1].f--){
					PII p = to[Ed[i].end]; int id = p2[q].front(); p2[q].pop_front();
					p.second ? (void)(dir[p.first][p.second] = id) : p1[p.first][0].push_back(id);
				}

		//getans D = 0
		for(auto p : len){
			deque < int > &now = p1[p][0]; dir[p][0] = now.front();
			while(sz(now)){
				for(int i = 0 ; i + 1 < p ; ++i) ans[now[i]] = now[i + 1];
				ans[now[p - 1]] = now[0];
				for(int i = 0 ; i < p ; now.pop_front() , ++i);
			}
		}

		//getans dir & LD
		for(auto p : len)
			for(int q = 1 ; q <= mxd[p] ; ++q){
				ans[dir[p][q]] = dir[p][q - 1];
				for(auto t : p1[p][q]) ans[t] = dir[p][q - 1];
			}

		//getans L?
		for(auto p : len) for(auto q : p3[p]) ans[q] = dir[p][0];
		
		//getans ?D
		for(int i = 0 ; i <= allmx ; ++i) for(auto q : p2[i]) ans[q] = i ? dir[t][i - 1] : q;

		//getans ??
		for(auto p : p4) ans[p] = p;

		for(int i = 1 ; i <= N ; ++i) printf("%d " , ans[i]);
		return 0;
	}
	puts("-1"); return 0;
}