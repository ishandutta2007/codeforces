#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
const int MOD = 1e9 + 7 , INV2 = (MOD + 1) >> 1;
int K , L , R , A[407] , C[407][407];

template < class T >
T poww(T a , int b){
	T times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

struct PII{
	int st , nd;
	PII(int _st = 0 , int _nd = 0) : st(_st) , nd(_nd){}
	PII operator =(int b){return *this = PII(b , 0);}
	bool operator !=(PII a){return st != a.st || nd != a.nd;}
};
PII operator +(PII a , PII b){return PII((a.st + b.st) % MOD , (a.nd + b.nd) % MOD);}
PII operator -(PII a , PII b){return PII((a.st + MOD - b.st) % MOD , (a.nd + MOD - b.nd) % MOD);}
PII operator *(PII a , PII b){return PII((a.st * b.st + 5 * a.nd * b.nd) % MOD , (a.st * b.nd + a.nd * b.st) % MOD);}
PII operator *(PII a , int b){return PII(a.st * b % MOD , a.nd * b % MOD);}
PII operator %(PII a , int b){return a;}
PII operator /(PII a , PII b){return a * PII(b.st , MOD - b.nd) * poww((b.st * b.st - 5 * b.nd * b.nd % MOD + MOD) % MOD , MOD - 2);}

void init(){
	A[1] = 1;
	int times = 1;
	for(int i = 1 ; i < K ; ++i){
		times = times * (i + 1) % MOD;
		for(int j = i + 1 ; j ; --j)
			A[j] = (A[j] * (MOD - i) + A[j - 1]) % MOD;
	}
	times = poww(times , MOD - 2);
	for(int i = 1 ; i <= K ; ++i)
		A[i] = A[i] * times % MOD;
	for(int i = 0 ; i <= K ; ++i){
		C[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}

int solve(int x , int k){
	PII all(0 , 0);
	for(int j = 0 ; j <= k ; ++j){
		PII cur = poww(PII(INV2 , INV2) , j) * poww(PII(INV2 , MOD - INV2) , k - j);
		if(cur != PII(1 , 0))
			all = all + (poww(cur , x + 1) - PII(1 , 0)) / (cur - PII(1 , 0)) * poww(MOD - 1 , k - j) * C[k][j];
		else
			all = all + PII((x + 1) % MOD , 0) * poww(MOD - 1 , k - j) * C[k][j];
	}
	all = all * poww(PII(0 , poww(5ll , MOD - 2)) , k);
	return all.st;
}

signed main(){
	cin >> K >> L >> R;
	init(); L += 2; R += 2;
	int ans = 0;
	for(int i = 1 ; i <= K ; ++i)
		ans = (ans + (solve(R , i) - solve(L - 1 , i) + MOD) * A[i]) % MOD;
	cout << ans;
	return 0;
}