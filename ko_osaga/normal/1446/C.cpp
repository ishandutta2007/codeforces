#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXT = 7000000;

int n;
int trie[MAXT][2], sz[MAXT], piv, term[MAXT], dp[MAXT];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		lint x; scanf("%lld",&x);
		vector<int> seq;
		for(int j = 29; j >= 0; j--){
			seq.push_back((x >> j) & 1);
		}
		int p = 0;
		for(auto &j : seq){
			if(!trie[p][j]){
				trie[p][j] = ++piv;
			}
			p = trie[p][j];
		}
		sz[p]++;
		term[p] = 1;
	}
	int ret = 1;
	for(int i=piv; i>=0; i--){
		vector<pi> p;
		for(int j=0; j<2; j++){
			if(trie[i][j]){
				sz[i] += sz[trie[i][j]];
				p.emplace_back(min(sz[trie[i][j]], 1), dp[trie[i][j]]);
			}
			else p.emplace_back(0, 0);
		}
		if(term[i]){
			dp[i] = sz[i];
		}
		else{
			dp[i] = max({
				p[0].first + p[1].first,
				p[0].first + p[1].second,
				p[0].second + p[1].first});
		}
	}
	cout << n - dp[0] <<endl;
}