#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1000000007;

long long ipow(long long a, long long b, long long mod = MOD){
	long long z = 1;
	for (long long i = 1ll<<30ll; i; i >>= 1ll){
		z = z * z % mod;
		if (i & b){
			z = z * a % mod;
		}
	}
	return z;
}

vector<int> E[200005];
int P[200005];
int N;

int V[200005];

int n = 0;

void obidji(int x){
	V[x] = 1;
	n++;
	for (int y : E[x]) if (!V[y]) obidji(y);
}

int cikl(int x){
	int step = 1;
	while (V[x] > 0){
		V[x] = -step;
		step++;
		x = P[x];
	}
	return step - (-V[x]);
}

int main(){
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> P[i];
		E[i].push_back(P[i]);
		E[P[i]].push_back(i);
	}
	
	long long sol = 1;
	
	for (int i=1; i<=N; i++){
		if (!V[i]){
			n = 0;
			obidji(i);
			int k = cikl(i);
			sol = sol * (ipow(2, n) - ipow(2, n-k+1) + MOD) % MOD;
		}
	}
	
	cout << sol << endl;


	return 0;
}