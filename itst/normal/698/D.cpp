#include<bits/stdc++.h>
using namespace std;

#define int long long
struct vec{
	int x , y; vec(int _x = 0 , int _y = 0) : x(_x) , y(_y){}
	friend vec operator +(vec p , vec q){return vec(p.x + q.x , p.y + q.y);}
	friend vec operator -(vec p , vec q){return vec(p.x - q.x , p.y - q.y);}
	friend int operator *(vec p , vec q){return p.x * q.x + p.y * q.y;}
	friend int operator %(vec p , vec q){return p.x * q.y - p.y * q.x;}
}node[1010]; int N , K; bool vis[1010]; vector < int > in , to[10][1010];

bool dfs(int lft){
	if(!in.size()){return 1;} if(in.size() > lft) return 0;
	vector < int > peo; for(int i = 1 ; i <= K ; ++i) if(!vis[i]) peo.push_back(i);
	for(int i = 0 ; i < in.size() ; ++i){
		int t = in[i]; sort(peo.begin() , peo.end() , [&](int p , int q){return to[p][t].size() < to[q][t].size();});
		in.erase(in.begin() + i); vis[t] = 0; int sz = in.size();
		for(auto x : peo){
			vis[x] = 1; for(auto r : to[x][t]) if(!vis[r]){vis[r] = 1; in.push_back(r);} if(dfs(lft - 1)) return 1;
			vis[x] = 0; while(sz < in.size()){vis[in.back()] = 0; in.pop_back();}
		}
		in.insert(in.begin() + i , t); vis[t] = 1;
	}
	return 0;
}

signed main(){
	cin >> K >> N; for(int i = 1 ; i <= K + N ; ++i) cin >> node[i].x >> node[i].y;
	for(int i = 1 ; i <= K ; ++i)
		for(int j = K + 1 ; j <= K + N ; ++j)
			for(int k = K + 1 ; k <= K + N ; ++k)
				if(to[i][j].size() < 8 && k != j && (node[k] - node[i]) % (node[k] - node[j]) == 0
				   && (node[k] - node[i]) * (node[j] - node[i]) > 0 && (node[k] - node[j]) * (node[i] - node[j]) > 0)
					to[i][j].push_back(k);
	int ans = 0; for(int i = 1 ; i <= N ; ++i){memset(vis , 0 , sizeof(vis)); vis[K + i] = 1; in = {K + i}; ans += dfs(K);}
	cout << ans; return 0;
}