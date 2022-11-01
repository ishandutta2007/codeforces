#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define ull unsigned long long
const int P = 998244353;
int A[1503][1503] , id[1503][1503] , N; ull val[2][1503] , sum[2][1503] , cur[1503];
bool vis[3003][3003]; int dp[3003][3003] , sz[3003] , cnode , mx[1503] , mn[1503];
struct dat{ull p , q; int id;}; bool operator <(dat p , dat q){return p.p == q.p ? p.q < q.q : p.p < q.p;}

void run(int x){
	dp[x][0] = 1;
	for(int i = 1 ; i < x; ++i)
		if(vis[x][i]){
			run(i);
			for(int p = sz[x] ; ~p ; --p){
				for(int q = 1 ; q <= sz[i] ; ++q)
					dp[x][p + q] = (dp[x][p + q] + 1ll * dp[x][p] * dp[i][q]) % P;
				dp[x][p] = 0;
			}
			sz[x] += sz[i];
		}
	dp[x][0] = 0; dp[x][1] = (dp[x][1] + 1) % P;
}

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) A[i][j] = read();
	mt19937_64 rnd(time(0)); for(int i = 0 ; i < 2 ; ++i) for(int j = 1 ; j <= N ; ++j) val[i][j] = rnd();
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= N ; ++j) id[i][j] = j;
		sort(id[i] + 1 , id[i] + N + 1 , [&](int p , int q){return A[i][p] < A[i][q];});
	}
	vector < dat > tmp;
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= N; ++j){
			for(int k = 0 ; k < 2 ; ++k) sum[k][j] ^= val[k][id[j][i]];
			mx[j] = A[j][id[j][i]]; mn[j] = A[j][id[j][i + 1]];
		}
		tmp.clear(); for(int j = 1 ; j <= N ; ++j) tmp.push_back((dat){sum[0][j] , sum[1][j] , j});
		sort(tmp.begin() , tmp.end()); int pt = 0;
		while(pt < tmp.size()){
			int p = pt; while(p < tmp.size() && tmp[p].p == tmp[pt].p && tmp[p].q == tmp[pt].q) ++p;
			if(p - pt == i){
				++cnode; int x = 0 , n = 1e9; if(i == 1) sz[cnode] = 1;
				for(int k = pt ; k < p ; ++k){x = max(x , mx[tmp[k].id]); n = min(n , mn[tmp[k].id]);}
				if(x < n || i == N)
					for(int k = pt ; k < p ; ++k){vis[cnode][cur[tmp[k].id]] = 1; cur[tmp[k].id] = cnode;}
			}
			pt = p;
		}
	}
	run(cnode); for(int i = 1 ; i <= N ; ++i) cout << dp[cnode][i] << ' ';
	return 0;
}