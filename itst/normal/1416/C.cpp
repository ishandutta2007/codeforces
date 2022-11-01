#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > cur , tmp;

int main(){
	ios::sync_with_stdio(0); int N; cin >> N;vector < int > pot;
	for(int i = 1 ; i <= N ; ++i){int A; cin >> A; pot.push_back(A);}
	cur.push_back(pot); long long ans = 0 , x = 0;
	for(int i = 30 ; ~i ; --i){
		long long cnt1 = 0 , cnt0 = 0 , sum1 = 0 , sum0 = 0; tmp.clear();
		for(auto t : cur){
			cnt1 = cnt0 = 0; vector < int > pl , pr;
			for(auto p : t)
				if(p >> i & 1){sum1 += cnt0; ++cnt1; pl.push_back(p);}
				else{sum0 += cnt1; ++cnt0; pr.push_back(p);}
			if(pl.size()) tmp.push_back(pl);
			if(pr.size()) tmp.push_back(pr);
		}
		ans += min(sum0 , sum1); x |= (sum1 < sum0) << i;
		cur = tmp;
	}
	cout << ans << ' ' << x << endl;
	return 0;
}