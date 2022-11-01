#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , P = 1e9 + 7;
int N , A[_] , prm[_] , cprm , phi[_] , cnt[_]; bool nprm[_]; vector < int > lst[_];
void sieve(){
	phi[1] = 1;
	for(int i = 2 ; i <= 1e5 ; ++i){
		if(!nprm[i]){prm[++cprm] = i; phi[i] = i - 1;}
		for(int j = 1 ; prm[j] * i <= 1e5 ; ++j){
			nprm[prm[j] * i] = 1; if(i % prm[j] == 0){phi[i * prm[j]] = phi[i] * prm[j]; break;}
			phi[i * prm[j]] = phi[i] * (prm[j] - 1);
		}
	}
	for(int i = 1 ; i <= 1e5 ; ++i) for(int j = i ; j <= 1e5 ; j += i) lst[j].push_back(i);
}

int main(){
	ios::sync_with_stdio(0); sieve(); cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	int ans = 0; vector < int > vis;
	for(int d = 1 ; d <= N ; ++d){
		for(int t = d ; t <= N ; t += d)
			for(auto v : lst[A[t]]) if(!(cnt[v]++)) vis.push_back(v);
		for(auto t : vis){ans = (ans + 1ll * phi[d] * phi[t] % P * cnt[t] * cnt[t]) % P; cnt[t] = 0;}
		vis.clear();		
	}
	cout << ans; return 0;
}