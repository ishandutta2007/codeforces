#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 10004205361450474ll;

int dp[10010][5];
vector < int > query;

int dfs(int l , int q){
	if(!q)
		return 0;
	if(l > 10000)
		l = 10000;
	if(dp[l][q])
		return dp[l][q];
	int r = l;
	for(int i = 1 ; i <= l ; ++i)
		r = r + dfs(r , q - 1) + 1;
	r = r + dfs(r , q - 1);
	return dp[l][q] = r - l;
}

void interact(){
	int cur = 1 , q = 5 , K;
	for(int i = 1 ; i <= 5 ; ++i){
		query.clear();
		query.push_back(cur - 1);
		int now = cur;
		for(int j = 1 ; j <= min(cur , 10000ll) ; ++j){
			now += dp[min(now , 10000ll)][q - 1];
			query.push_back(now);
			++now;
		}
		cout << query.size() - 1 << ' ';
		for(int i = 1 ; i < query.size() ; ++i)
			cout << query[i] << ' ';
		cout << endl;
		cin >> K;
		if(K == -1)
			exit(0);
		cur = query[K] + 1;
		--q;
	}
}

signed main(){
	dfs(1 , 5);
	interact();
	return 0;
}