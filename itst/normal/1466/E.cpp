#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read(){
	ll a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int P = 1e9 + 7; int T , N , cnt[63]; ll X[500003];

int main(){
	for(T = read() ; T ; --T){
		memset(cnt , 0 , sizeof(cnt)); N = read(); int ans = 0;
		for(int i = 1 ; i <= N ; ++i){X[i] = read(); for(int j = 0 ; j < 60 ; ++j) cnt[j] += X[i] >> j & 1;}
		for(int i = 1 ; i <= N ; ++i){
			int suml = 0 , sumr = 0;
			for(int j = 0 ; j < 60 ; ++j){
				if(X[i] >> j & 1){suml = (suml + (1ll << j) % P * cnt[j]) % P; sumr = (sumr + (1ll << j) % P * N) % P;}
				else sumr = (sumr + (1ll << j) % P * cnt[j]) % P;
			}
			ans = (ans + 1ll * suml * sumr) % P;
		}
		cout << ans << endl;
	}
	return 0;
}