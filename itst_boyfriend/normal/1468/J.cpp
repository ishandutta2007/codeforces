#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , M , K , fa[_];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
struct Edge{int s , t , w;}Ed[_];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M >> K; for(int i = 1 ; i <= N ; ++i) fa[i] = i;
		for(int i = 1 ; i <= M ; ++i) cin >> Ed[i].s >> Ed[i].t >> Ed[i].w;
		int p = 0 , cnt = 0; long long sum = 0;
		sort(Ed + 1 , Ed + M + 1 , [&](Edge p , Edge q){return p.w < q.w;});
		while(cnt != N - 1){++p; if(find(Ed[p].s) != find(Ed[p].t)){fa[find(Ed[p].s)] = Ed[p].t; ++cnt; sum += max(0 , Ed[p].w - K);}}
		if(Ed[p].w >= K)cout << sum << endl;
		else{
			while(p <= M && Ed[p].w < K) ++p;
			if(p == M + 1) cout << K - Ed[p - 1].w << endl;
			else cout << min(K - Ed[p - 1].w , Ed[p].w - K) << endl;
		}
	}
	return 0;
}