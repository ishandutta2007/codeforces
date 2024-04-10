#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; int deg[_] , T , N , w[_]; long long ans;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; ans = 0; for(int i = 1 ; i <= N ; ++i){deg[i] = 0; cin >> w[i]; ans += w[i];}
		for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; ++deg[p]; ++deg[q];}
		vector < int > val; for(int i = 1 ; i <= N ; ++i) for(int j = 2 ; j <= deg[i] ; ++j) val.push_back(w[i]);
		sort(val.begin() , val.end() , [&](int p , int q){return p > q;}); cout << ans << ' ';
		for(auto t : val) cout << (ans += t) << ' ';
		cout << endl;
	}
	return 0;
}