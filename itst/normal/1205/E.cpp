#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair < int , int >
const int _ = 1e5 + 7 , MOD = 1e9 + 7;
int N , K , ans = 0 , mu[_] , prm[_] , cnt; bool nprm[_];
vector < int > ys[_];

int add(int a , int b){return a + b >= MOD ? a + b - MOD : a + b;}
int poww(int a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

void init(){
	mu[1] = 1;
	for(int i = 2 ; i <= N ; ++i){
		if(!nprm[i]) mu[prm[++cnt] = i] = -1;
		for(int j = 1 ; prm[j] * i <= N ; ++j){
			nprm[prm[j] * i] = 1;
			if(i % prm[j] == 0) break;
			mu[prm[j] * i] = -mu[i];
		}
	}
}

signed main(){
	cin >> N >> K; init();
	//for(int i = 1 ; i < N ; ++i) ans = add(ans , poww(poww(K , MOD - 2) , i));
	for(int i = 1 ; i < N ; ++i)
		for(int j = i ; j < N ; j += i)
			ys[j].push_back(i);
	for(int T = 1 ; T < N ; ++T){
		static int sum[_ << 1]; int R = (N - 1) / T , sum1 = 0 , sum2 = 0; sum[2 * R + 1] = 0;
		for(int j = 2 ; j <= 2 * R ; ++j)
			sum[j] = (j <= R + 1 ? (j - 1) : (2 * R - j + 1)) * poww(K , T * j) % MOD;
		for(int j = 2 * R - 1 ; j >= 2 ; --j)
			sum[j] = add(sum[j] , sum[j + 1]);
#define ch2(x) ((x) * ((x) + 1) / 2 % MOD)
		for(auto t : ys[T])
			if(mu[T / t]){
				int rge = min(2 * R , (N - 1 + t) / T) , area = rge <= R + 1 ? ch2(rge - 1) : R * R - ch2(2 * R - rge);
				sum1 = (sum1 + poww(K , t) * mu[T / t] * area % MOD + MOD) % MOD;
				sum2 = (sum2 + mu[T / t] * sum[rge + 1] + MOD) % MOD;
			}
		ans = (ans + sum1 * poww(poww(K , MOD - 2) , N) + sum2 * poww(poww(K , MOD - 2) , 2 * N)) % MOD;
	}
	cout << ans;
	return 0;
}