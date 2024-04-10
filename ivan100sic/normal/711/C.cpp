#include "bits/stdc++.h"
using namespace std;

int N, K, M;
int A[105];
long long cost[105][105];
long long D[105][105][105];
long long LL[105][105][105];
long long RR[105][105][105];

long long range_min(int i, int k, int lo, int hi){
	if (lo == 1) return LL[i][k][hi];
	if (hi == M) return RR[i][k][lo];
	return 1e15;
}

int main(){
	
	cin >> N >> M >> K;
	
	for (int i=1; i<=N; i++) cin >> A[i];
	
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			cin >> cost[i][j];
			if (A[i] != 0){
				if (A[i] == j){
					cost[i][j] = 0;
				} else {
					cost[i][j] = 1e14;
				}
			}
			// cout << cost[i][j] << endl;
		}
	}
	
	memset(D, 63, sizeof(D));
	memset(LL, 63, sizeof(LL));
	memset(RR, 63, sizeof(RR));
	{
		for (int i=1; i<=M; i++) D[1][1][i] = cost[1][i];
		
		int i = 1;
		int k = 1;
		LL[i][k][1] = D[i][k][1];
		for (int c=2; c<=M; c++) LL[i][k][c] = min(LL[i][k][c-1], D[i][k][c]);
		
		RR[i][k][M] = D[i][k][M];
		for (int c=M-1; c>=1; c--) RR[i][k][c] = min(RR[i][k][c+1], D[i][k][c]);
	}
	
	for (int i=2; i<=N; i++){
		for (int k=1; k<=K; k++){
			for (int c=1; c<=M; c++){
				// varijanta 1: uzimamo istu za prethodnu
				D[i][k][c] = D[i-1][k][c] + cost[i][c];

				// varijanta 2: uzimamo razlicitu za prethodnu
				D[i][k][c] = min(
					min (
						range_min(i-1, k-1, 1, c-1),
						range_min(i-1, k-1, c+1, M)
					) + cost[i][c],
					
					D[i][k][c]
				);
				
				//cout << i << k << c << ' ' << D[i][k][c] << endl;
			}
			
			LL[i][k][1] = D[i][k][1];
			for (int c=2; c<=M; c++) LL[i][k][c] = min(LL[i][k][c-1], D[i][k][c]);
			
			RR[i][k][M] = D[i][k][M];
			for (int c=M-1; c>=1; c--) RR[i][k][c] = min(RR[i][k][c+1], D[i][k][c]);			
		}
	}
	
	long long s = range_min(N, K, 1, M);
	if (s > 0.99e14) s = -1;
	
	cout << s << endl;
	
	//cin >> s;

	return 0;
}