#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
#define ll long long
//This code is written by Itst
using namespace std;

const int MOD = 1e9 + 7;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	ll N , M , sum = 0 , inv_2 = 5e8 + 4;
	cin >> N >> M;
	for(ll i = 1 , pi ; i <= N && i <= M ; i = pi + 1){
		pi = min(M , N / (N / i));
		(sum += (pi - i + 1) % MOD * ((pi + i) % MOD) % MOD * inv_2 % MOD * (N / i) % MOD) %= MOD;
	}
	cout << (N % MOD * (M % MOD) - sum + MOD) % MOD;
	return 0;
}