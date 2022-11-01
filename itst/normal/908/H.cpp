#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int _ = 1 << 23; ull ans[_] , vis[_] , ppc[_]; char Map[48][48]; int N , sz[48] , fa[48] , bel[48];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void fwt(ull *arr , int sz){
	for(int i = 0 ; i < sz ; ++i)
		for(int j = 0 ; j < 1 << sz ; j += 1 << (i + 1))
			for(int k = 0 ; k < 1 << i ; ++k) arr[j | k | (1 << i)] += arr[j | k];
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){fa[i] = i; sz[i] = 1; bel[i] = -1;}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			cin >> Map[i][j]; assert((i == j) ^ (Map[i][j] == '-') ^ 1);
			if(Map[i][j] == 'A' && find(i) != find(j)){sz[find(i)] += sz[find(j)]; fa[find(j)] = find(i);}
		}
	int cid = 0; for(int i = 1 ; i <= N ; ++i) if(fa[i] == i && sz[i] != 1) bel[i] = cid++;
	
	for(int i = 0 ; i < 1 << cid ; ++i) ans[i] = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j){
			assert(Map[i][j] == Map[j][i]);
			if(Map[i][j] == 'X')
				if(find(i) == find(j)){puts("-1"); return 0;}
				else if(bel[find(i)] != -1 && bel[find(j)] != -1) vis[(1 << bel[find(i)]) | (1 << bel[find(j)])] = 1;
		}
	fwt(vis , cid); for(int i = 0 ; i < 1 << cid ; ++i){vis[i] = !vis[i];} fwt(vis , cid);
	for(int i = 1 ; i < 1 << cid ; ++i) ppc[i] = ppc[i >> 1] + (i & 1);
	
	for(int i = 0 ; i <= cid ; ++i){
		ull sum = 0; for(int j = 0 ; j < 1 << cid ; ++j) sum += ans[j] * ((cid - ppc[j]) & 1 ? -1 : 1);
		if(sum){cout << N - 1 + i; break;} for(int j = 0 ; j < 1 << cid ; ++j) ans[j] *= vis[j];
	}
	
	return 0;
}