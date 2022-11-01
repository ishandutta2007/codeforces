#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define ms(n) memset(n,0,sizeof(n))
#define pb push_back
#define uint unsigned int
using namespace std;

int n;
int t[1000001];
int tsum = 0;
int root;
int ans1;
int to[1000001];
bool done = 0;

vector<int> e[1000001];

bool vis[1000001];
int sum[1000001];
void dfs(int pos){
	if(pos == root) return;
	if(vis[pos] != 0) return;
	if(done) return;
	vis[pos] = 1;
	
	for(uint i = 0;i < e[pos].size();i++){
		if(done) return;
		if(e[pos][i] != to[pos]){
			dfs(e[pos][i]);
			sum[pos] += sum[e[pos][i]];
		}
	}
	if(sum[pos] == tsum/3){
		sum[pos] = 0;
		if(ans1 == 0)
			ans1 = pos;
		else{
			if(done) return;
			done = 1;
			cout << ans1 << " " << pos << endl;
			return;
		}
	}
	dfs(to[pos]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int too;
		cin >> too;
		if(too != 0){
			e[i].pb(too);
			e[too].pb(i);
		}else{
			root = i;
		}
		to[i] = too;
		cin >> sum[i];
		tsum += sum[i];
	}
	
	if(tsum%3 != 0){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 1;i <= n;i++){
		if(done) return 0;
		if(e[i].size() == 1  &&  i != root)
			dfs(i);
	}
		
	if(!done)
		cout << -1 << endl;
		
	return 0;
}