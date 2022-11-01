#include<bits/stdc++.h>
using namespace std;

const int P = 998244353 , _ = 2e5 + 7; vector < int > nxt[_][2];
int N , M;
struct dat{
	int stp , k;
	friend bool operator <(dat p , dat q){
		if(p.k >= 19 && q.k >= 19) return p.k < q.k || p.k == q.k && p.stp < q.stp;
		if(p.k >= 19) return 0;
		if(q.k >= 19) return 1;
		return (1 << p.k) + p.stp < (1 << q.k) + q.stp;
	}
	friend bool operator >(dat p , dat q){return q < p;}
}dst[_][2][20];
struct qdat{
	dat p; int x , y , z;
	friend bool operator <(qdat p , qdat q){return q.p < p.p;}
}; priority_queue < qdat > q;

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1; i <= M ; ++i){
		int u , v; cin >> u >> v;
		nxt[u][0].push_back(v); nxt[v][1].push_back(u);
	}
	for(int i= 1 ; i <= N ; ++i)
		for(int j = 0 ; j < 2 ; ++j)
			for(int k = 0 ; k <= 19 ; ++k) dst[i][j][k] = (dat){(int)1e9 , (int)1e9};
	dst[1][0][0] = (dat){0 , 0}; q.push((qdat){dst[1][0][0] , 1 , 0 , 0});
	while(!q.empty()){
		int x = q.top().x , y = q.top().y , z = q.top().z; q.pop();
		dat r = dst[x][y][z]; ++r.k;
		if(dst[x][y ^ 1][min(z + 1 , 19)] > r){
			dst[x][y ^ 1][min(z + 1 , 19)] = r;
			q.push((qdat){dst[x][y ^ 1][min(z + 1 , 19)] , x , y ^ 1 , min(z + 1 , 19)});
		}
		for(auto t : nxt[x][y]){
			r = dst[x][y][z]; ++r.stp;
			if(dst[t][y][z] > r){
				dst[t][y][z] = r; q.push((qdat){dst[t][y][z] , t , y , z});
			}
		}		
	}
	dat ans = (dat){(int)1e9 , (int)1e9};
	for(int i = 0 ; i <= 19 ; ++i) ans = min(ans , min(dst[N][0][i] , dst[N][1][i]));
	int tms = 1; for(int i = 1 ; i <= ans.k ; ++i) tms = 2ll * tms % P;
	cout << (tms + ans.stp - 1 +P) % P;
	return 0;
}