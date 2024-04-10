#include "bits/stdc++.h"
using namespace std;

int N, C[100005];
int K, G[100005];

bool IsCap[100005];

long long sol = 0, tot = 0, totcap = 0;

int main(){
	cin >> N >> K;
	
	for (int i=1; i<=N; i++) cin >> C[i];
	
	for (int i=1; i<=K; i++){
		cin >> G[i];
		IsCap[G[i]] = true;
	}
	
	C[N+1] = C[1];
	C[0] = C[N];
	IsCap[N+1] = IsCap[1];
	IsCap[0] = IsCap[N];
	
	for (int i=1; i<=N; i++){
		tot += C[i];
		if (IsCap[i]) totcap += C[i];
	}
	
	for (int i=1; i<=K; i++){
		int y = G[i];
		sol += 2 * C[y] * (tot - totcap) + C[y] * (totcap - C[y]);
	}
	
	for (int i=1; i<=N; i++){
		if (!IsCap[i] && !IsCap[i+1]) sol += 2ll * C[i] * C[i+1];
	}
	
	cout << sol / 2 << endl;



	return 0;
}