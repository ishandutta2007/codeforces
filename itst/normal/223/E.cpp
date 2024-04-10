#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7;
#define ld long double
struct comp{
	int x , y; comp(int _x = 0 , int _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp p , comp q){return comp(p.x + q.x , p.y + q.y);}
	friend comp operator -(comp p , comp q){return comp(p.x - q.x , p.y - q.y);}
	ld ang(){return atan2(y , x);}
}point[_]; vector < int > nxt[_] , val[_]; int N , M , Q;

void shift(vector < int > &vec , int st){vec.insert(vec.end() , vec.begin() , vec.begin() + st); vec.erase(vec.begin() , vec.begin() + st);}

map < int , int > id[_]; vector < int > nxtsz[_]; int sz[_] , dep[_];
void dfs(int x , int p){
	sort(nxt[x].begin() , nxt[x].end() , [&](int p , int q){return (point[p] - point[x]).ang() < (point[q] - point[x]).ang();});
	shift(nxt[x] , find(nxt[x].begin() , nxt[x].end() , p) - nxt[x].begin());
	nxtsz[x].push_back(0); sz[x] = 1; dep[x] = dep[p] + 1;
	for(int i = 0 ; i < nxt[x].size() ; ++i){
		int delt = 0; id[x][nxt[x][i]] = i + 1;
		if(!sz[nxt[x][i]]){dfs(nxt[x][i] , x); delt = -sz[nxt[x][i]]; sz[x] += sz[nxt[x][i]];}
		nxtsz[x].push_back(delt);
	}
	for(int i = 1 ; i <= nxt[x].size() ; ++i){
		if(nxt[x][i - 1] == p) nxtsz[x][i] = sz[x];
		nxtsz[x][i] += nxtsz[x][i - 1];
	}
}

int qry(int x , int l , int r){l = id[x][l]; r = id[x][r]; return nxtsz[x][l - 1] - nxtsz[x][r] + (l < r ? nxtsz[x].back() : 0);}

int main(){
	cin >> N >> M; for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= N ; ++i) cin >> point[i].x >> point[i].y;
	int mn = 1; for(int i = 1 ; i <= N ; ++i) if(point[i].x < point[mn].x) mn = i;
	point[0] = point[mn]; --point[0].x; nxt[0].push_back(mn); nxt[mn].push_back(0); dfs(0 , 0);
	for(cin >> Q ; Q ; --Q){
		vector < int > node; int K; cin >> K; for(int i = 0 ; i < K ; ++i){int x; cin >> x; node.push_back(x);}
		int mn = 0; for(int i = 1 ; i < node.size() ; ++i) if(dep[node[i]] < dep[node[mn]]) mn = i;
		shift(node , mn); if(id[node[0]][node[1]] > id[node[0]][node.back()]) reverse(node.begin() + 1 , node.end());
		int sum = qry(node[0] , node[1] , node.back()); node.push_back(node[0]);
		for(int i = 1 ; i + 1 < node.size() ; ++i) sum += qry(node[i] , node[i + 1] , node[i - 1]);
		cout << sum << endl;
	}
	return 0;
}