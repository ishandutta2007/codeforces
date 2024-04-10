#include "bits/stdc++.h"
using namespace std;

double Q[20], S[20], D[1 << 20];
int N, K;

inline double e(double x){
	return x / (1-x);
}

inline bool in(int i, int mask){
	return mask & (1 << i);
}

inline int _coef(int k){
	int r = 1, mn = K-N;
	k = K-k;
	for (int i=1; i<k; i++){
		r *= mn;
		mn--;
		r /= i;
	}
	return r;
}

inline int coef(int k){
	static int coefs[20] = {0};
	if (!coefs[k]) coefs[k] = _coef(k);
	return coefs[k];
}

int main(){
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++){
		scanf("%lf", Q+i);
	}
	
	/* specijalni slucaj */

	for (int i=0; i<N; i++){
		if (Q[i] == 1.0){
			for (int i=0; i<N; i++) printf("%.14lf ", Q[i]);
			return 0;
		}
	}	
	
	for (int mask=0; mask<(1<<N); mask++){
		double sum=0;
		int k = 0;
		for (int i=0; i<N; i++) if (in(i, mask)){
			sum += Q[i];
			k++;
		}
		D[mask] = e(sum);
		if (k < K){
			for (int i=0; i<N; i++) if (!in(i, mask)){
				S[i] += coef(k) * D[mask];
			}
		}
	}
	for (int i=0; i<N; i++) if (isinf(S[i]) || isnan(S[i])) S[i] = 0;
	for (int i=0; i<N; i++) printf("%.14lf ", (S[i]+1) * Q[i]);
	scanf("%d", &N);
	return 0;
}

/*
10 5
0.02 0.17 0.04 0.07 0.21 0.06 0.09 0.11 0.17 0.06

Expected:
0.1399910871034487 0.7479501842209872 0.2655803706306279 0.4263090048227962...
*/