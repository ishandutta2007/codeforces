#include<bits/stdc++.h>
using namespace std;

const int P = 998244353; int T , N , A[100003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		vector < pair < int , int > > pot , tmp; pot.push_back(make_pair(100001 , 1));
		int ans = 0;
		for(int i = N ; i ; --i){
			tmp.clear(); int sum = 0; tmp.push_back(make_pair(1e5 + 1 , 1));
			for(auto t : pot){
				int p = A[i] , q = t.second;
				if(t.first < A[i]){
					int num = (A[i] - 1) / t.first; sum = (sum + 1ll * num * t.second) % P;
					p = A[i] / (num + 1);
				}
				if(tmp.size() && tmp.back().first == p) tmp.back().second += q;
				else tmp.push_back(make_pair(p , q));
			}
			ans = (ans + 1ll * sum * i) % P; pot = tmp;
		}
		cout << ans << endl;
	}
	return 0;
}