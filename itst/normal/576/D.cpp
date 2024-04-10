#include<bits/stdc++.h>
using namespace std;

struct matrix{
	bitset < 150 > A[150] , T[150];
	friend matrix operator *(matrix x , matrix y){
		matrix z;
		for(int i = 0 ; i < 150 ; ++i)
			if(x.A[i].count())
				for(int j = 0 ; j < 150 ; ++j)
					z.A[i][j] = z.T[j][i] = (x.A[i] & y.T[j]).count();
		return z;
	}
}G , T , C;
int N , M , s[153] , t[153] , d[153] , id[153] , ans;
vector < int > nxt[153];

int dis[153];
void work(int now){
	memset(dis , 0x7f , sizeof(dis)); queue < int > q;
	for(int i = 0 ; i < N ; ++i) if(G.A[0][i]){dis[i] = now; q.push(i);}
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(auto x : nxt[t])
			if(dis[x] > dis[t] + 1){dis[x] = dis[t] + 1; q.push(x);}
	}
	ans = min(ans , dis[N - 1]);
}

int main(){
	cin >> N >> M; ans = 2e9;
	for(int i = 1 ; i <= M ; ++i){cin >> s[i] >> t[i] >> d[i]; id[i] = i; --s[i]; --t[i];}
	sort(id + 1 , id + M + 1 , [&](int x , int y){return d[x] < d[y];});
	if(d[id[1]] > 0){puts("Impossible"); return 0;}
	int pos = 1; G.A[0][0] = 1;
	while(pos <= M && d[id[pos]] <= ans){
		int pos1 = pos;
		while(pos1 <= M && d[id[pos]] == d[id[pos1]]){
			T.A[s[id[pos1]]][t[id[pos1]]] = T.T[t[id[pos1]]][s[id[pos1]]] = 1;
			nxt[s[id[pos1]]].push_back(t[id[pos1]]); ++pos1;
		}
		work(d[id[pos]]); C = T;
		int K = max(0 , d[id[pos1]] - d[id[pos]]);
		while(K){
			if(K & 1) G = G * C;
			C = C * C; K >>= 1;
		}
		pos = pos1;
	}
	if(ans == 2e9) puts("Impossible"); else cout << ans;
	return 0;
}