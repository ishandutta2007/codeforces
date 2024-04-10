#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define ll long long
inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

#define PII pair < int , int >
#define st first
#define nd second
const int MAXN = 2.5e5 + 7;
struct Edge{
	int end , upEd , w;
}Ed[MAXN << 1];
int head[MAXN] , d[MAXN] , val[MAXN] , dep[MAXN] , jump[MAXN][20] , dfn[MAXN];
int ts , N , cntEd;

inline void addEd(int a , int b , int c){
	Ed[++cntEd] = (Edge){b , head[a] , c};
	head[a] = cntEd;
	++d[a];
}

void dfs(int x , int p){
	jump[x][0] = p; dep[x] = dep[p] + 1; dfn[x] = ++ts;
	for(int i = 1 ; jump[x][i - 1] ; ++i)
		jump[x][i] = jump[jump[x][i - 1]][i - 1];
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			val[Ed[i].end] = Ed[i].w;
			dfs(Ed[i].end , x);
		}
}

int LCA(int x , int y){
	if(dep[x] < dep[y])
		x ^= y ^= x ^= y;
	for(int i = 18 ; i >= 0 ; --i)
		if(dep[x] - (1 << i) >= dep[y])
			x = jump[x][i];
	if(x == y) return x;
	for(int i = 18 ; i >= 0 ; --i)
		if(jump[x][i] != jump[y][i]){
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

deque < PII > q;
multiset < int , greater < int > > notin[MAXN];
ll dp[MAXN][2] , all[MAXN];
int stk[MAXN] , top , cur;
vector < int > ch[MAXN] , node;

bool cmp(int a , int b){return dfn[a] < dfn[b];}

void create(){
	node.clear(); bool flg = 0;
	for(auto t : q){
		int p = t.nd; node.push_back(t.nd);
		flg |= p == 1;
		while(notin[p].size() > d[p] - cur){
			all[p] -= *notin[p].begin(); notin[p].erase(notin[p].begin());
		}
	}
	if(!flg) node.push_back(1);
	sort(node.begin() , node.end() , cmp);
	for(auto t : node){
		if(top > 1){
			int p = LCA(stk[top] , t);
			while(dep[stk[top - 1]] >= dep[p]){
				ch[stk[top - 1]].push_back(stk[top]);
				--top;
			}
			if(stk[top] != p){
				ch[p].push_back(stk[top]);
				stk[top] = p;
			}
		}
		stk[++top] = t;
	}
	while(--top)
		ch[stk[top]].push_back(stk[top + 1]);
}

void DP(int x){
	multiset < int , greater < int > > &tmp = notin[x] , erased , input;
	ll sum = all[x];
	for(auto t : ch[x]){
		DP(t);
		if(d[x] > cur && d[t] > cur)
			if(dep[t] == dep[x] + 1){
				sum += dp[t][0];
				if(tmp.size() < d[x] - cur){
					tmp.insert(dp[t][1] + val[t] - dp[t][0]);
					input.insert(dp[t][1] + val[t] - dp[t][0]);
					sum += dp[t][1] + val[t] - dp[t][0];
				}
				else
					if(*tmp.begin() > dp[t][1] + val[t] - dp[t][0]){
						if(*tmp.begin() > 0){
							erased.insert(*tmp.begin());
							sum -= *tmp.begin(); tmp.erase(tmp.begin());
							tmp.insert(dp[t][1] + val[t] - dp[t][0]);
							input.insert(dp[t][1] + val[t] - dp[t][0]);
						}
						sum += dp[t][1] + val[t] - dp[t][0];
					}
					else if(dp[t][1] + val[t] - dp[t][0] < 0)
						sum += dp[t][1] + val[t] - dp[t][0];
			}
			else
				sum += min(dp[t][0] , dp[t][1] + val[t]);
		else sum += min(dp[t][0] , dp[t][1] + val[t]);
		dp[t][0] = dp[t][1] = 0;
	}
	if(cur == 0){
		dp[x][0] = dp[x][1] = sum;
	}
	else{
		dp[x][0] = sum;
		if(!tmp.empty() && *tmp.begin() > 0)
			dp[x][1] = sum - *tmp.begin();
		else dp[x][1] = sum;
	}
	ch[x].clear();
	for(auto t : erased) tmp.insert(t);
	for(auto t : input) tmp.erase(tmp.find(t));
}

signed main(){
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read() , c = read();
		addEd(a , b , c); addEd(b , a , c);
	}
	dfs(1 , 0);
	for(int i = 1 ; i <= N ; ++i)
		q.push_back(PII(d[i] , i));
	sort(q.begin() , q.end());
	for(cur = 0 ; cur < N ; ++cur){
		while(!q.empty() && q.front().st == cur){
			int t = q.front().nd;
			if(d[jump[t][0]] > cur){
				notin[jump[t][0]].insert(val[t]);
				all[jump[t][0]] += val[t];
			}
			notin[t].clear(); all[t] = 0;
			q.pop_front();
		}
		create(); DP(1); printf("%lld " , dp[1][0]);
		dp[1][0] = dp[1][1] = 0;
	}
	return 0;
}