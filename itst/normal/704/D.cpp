#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;
 
int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}
 
const int _ = 3e5 + 7;
namespace flow{
	const int __ = 1e7 + 7;
	struct Edge{
		int end , upEd , f;
	}Ed[__];
	int head[_] , cur[_] , dep[_] , cntEd = 1 , S , T;
	queue < int > q;
	
	void addEd(int a , int b , int c){
		Ed[++cntEd] = (Edge){b , head[a] , c};
		head[a] = cntEd;
	}
 
	void addE(int a , int b , int c , bool f = 0){
		addEd(a , b , c); addEd(b , a , f * c);
	}
 
	bool bfs(){
		while(!q.empty()) q.pop();
		memset(dep , 0 , sizeof(int) * (max(S , T) + 1));
		dep[S] = 1; q.push(S);
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(!dep[Ed[i].end] && Ed[i].f){
					dep[Ed[i].end] = dep[t] + 1;
					if(Ed[i].end == T){
						memcpy(cur , head , sizeof(int) * (max(T , S) + 1));
						return 1;
					}
					q.push(Ed[i].end);
				}
		}
		return 0;
	}
 
	int dfs(int x , int mn){
		if(x == T) return mn;
		int sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
				int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f));
				sum += t; Ed[i].f -= t; Ed[i ^ 1].f += t;
				if(sum == mn) break;
			}
		return sum;
	}
 
	int Dinic(int s , int t){
		S = s; T = t; int sum = 0;
		while(bfs())
			sum += dfs(s , 1e9);
		return sum;
	}
}
using namespace flow;
 
int N , M , cntx , cnty; long long R , B;
int x[_] , y[_] , mnx[_] , mny[_];
vector < int > px[_] , py[_];
map < int , int > lx , ly;
 
signed main(){
	N = read(); M = read(); R = read(); B = read();
	for(int i = 1 ; i <= N ; ++i){
		x[i] = read(); y[i] = read();
		if(!lx[x[i]]) lx[x[i]] = ++cntx;
		if(!ly[y[i]]) ly[y[i]] = ++cnty;
		x[i] = lx[x[i]]; y[i] = ly[y[i]];
		px[x[i]].push_back(i); py[y[i]].push_back(i);
	}
	memset(mnx , 0x3f , sizeof(mnx)); memset(mny , 0x3f , sizeof(mny));
	for(int i = 1 ; i <= M ; ++i){
		int tp = read() , pos = read() , d = read();
		if(tp == 1) mnx[lx[pos]] = min(mnx[lx[pos]] , d);
		else mny[ly[pos]] = min(mny[ly[pos]] , d);
	}
	int S = 0 , T = 2 * N + 1 , SS = T + 1 , TT = SS + 1 , sSS = 0 , sTT = 0 , all = 0;
	addE(T , S , 1e9);
	for(int i = 1 ; i <= cntx ; ++i){
		int L = max(((int)px[i].size() - mnx[i] + 1) / 2 , 0) , R = px[i].size() - L;
		if(L > R){puts("-1"); return 0;}
		addE(S , i , R - L); addE(SS , i , L); sTT += L; all += L;
		for(auto t : px[i]) addE(i , y[t] + N , 1);
	}
	for(int i = 1 ; i <= cnty ; ++i){
		int L = max(((int)py[i].size() - mny[i] + 1) / 2 , 0) , R = py[i].size() - L;
		if(L > R){puts("-1"); return 0;}
		addE(i + N , T , R - L); addE(i + N , TT , L); sSS += L; all += L;
	}
	addE(S , TT , sTT); addE(SS , T , sSS);
	if(Dinic(SS , TT) != all){puts("-1"); return 0;}
	all = Ed[3].f; Ed[2].f = Ed[3].f = 0; head[SS] = head[TT] = 0;
	all = R < B ? all + Dinic(S , T) : all - Dinic(T , S);
	printf("%I64d\n" , all * R + (N - all) * B);
	static char ans[_];
	for(int i = 1 ; i <= cntx ; ++i){
		map < int , int > now;
		for(int j = head[i] ; j ; j = Ed[j].upEd)
			if(Ed[j].end >= N + 1 && Ed[j].end <= 2 * N)
				now[Ed[j].end - N] += Ed[j ^ 1].f;
		for(auto t : px[i])
			if(now[y[t]]){--now[y[t]]; ans[t] = 'r';}
			else ans[t] = 'b';
	}
	puts(ans + 1);
	return 0;
}