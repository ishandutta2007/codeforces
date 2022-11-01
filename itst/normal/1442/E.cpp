#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
int T , N , dp[_][2] , col[_]; vector < int > nxt[_];

void qdp(int x , int p , int mid){
	dp[x][0] = dp[x][1] = 1;
	if(col[x] == 1) dp[x][1] = 1e9; else if(col[x] == 2) dp[x][0] = 1e9;
	for(auto t : nxt[x])
		if(t != p){
			qdp(t , x , mid);
			static int tmp[2]; tmp[0] = tmp[1] = 1e9;
			for(int p = 0 ; p < 2 ; ++p)
				for(int q = 0 ; q < 2 ; ++q)
					if(dp[x][p] + dp[t][q] - (p == q) <= mid)
						tmp[p] = min(tmp[p] , max(dp[x][p] , dp[t][q] + (p != q)));
			dp[x][0] = tmp[0]; dp[x][1] = tmp[1];
		}
}

bool check(int mid){
	qdp(1 , 0 , mid); return dp[1][0] < 1e9 || dp[1][1] < 1e9;
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
		for(int i = 1 ; i <= N ; ++i) cin >> col[i];
		for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
		int L = 1 , R = N; while(L < R){int mid = (L + R) / 2; check(mid) ? R = mid : L = mid + 1;}
		cout << L / 2 + 1 << endl;
	}
	return 0;
}