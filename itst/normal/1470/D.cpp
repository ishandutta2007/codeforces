#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 3e5 + 7; int T , N , M; vector < int > nxt[_];
int fa[_]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	for(T = read() ; T ; --T){
		N = read(); M = read(); for(int i = 1 ; i <= N ; ++i){nxt[i].clear(); fa[i] = i;}
		for(int i = 1 ; i <= M ; ++i){int p = read() , q = read(); nxt[p].push_back(q); nxt[q].push_back(p); fa[find(p)] = find(q);}
		bool flg = 1; for(int i = 2 ; i <= N ; ++i) if(find(i) != find(1)) flg = 0;
		if(!flg) puts("NO");
		else{
			vector < int > seq; static bool vis[_] , ban[_]; for(int i = 1 ; i <= N ; ++i) vis[i] = ban[i] = 0;
			vis[1] = 1; set < int > in{1};
			while(in.size()){
				int t = *in.begin(); ban[t] = 1; in.erase(t); seq.push_back(t);
				for(auto p : nxt[t])
					if(!ban[p]){
						if(vis[p]){in.erase(p);} vis[p] = ban[p] = 1;
						for(auto q : nxt[p]){vis[q] = 1; if(!ban[q]) in.insert(q);}
					}
			}
			puts("YES");printf("%d\n" , seq.size()); for(auto t : seq) printf("%d " , t);
			puts("");
		}
	}
	return 0;
}