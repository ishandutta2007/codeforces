#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
	int T , N; ll W;
	for(cin >> T ; T ; --T){
		cin >> N >> W; vector < int > pot; ll sum = 0;
		for(int i = 1 ; i <= N ; ++i){
			int v; cin >> v; if(v > W || sum >= (W + 1) / 2) continue;
			if(v >= (W +1 ) / 2){pot = {i}; sum = v;}
			else{sum += v; pot.push_back(i);}
		}
		if(sum >= (W + 1) / 2){
			cout << pot.size() << '\n';
			for(auto p : pot) cout << p << ' ';
		}
		else cout << -1;
		cout << '\n';
	}
	return 0;
}