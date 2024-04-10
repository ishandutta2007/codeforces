#include "bits/stdc++.h"
using namespace std;

int N;
int A[100005];

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", A+i);
	
	sort(A, A+N);
	
	int q;
	scanf("%d", &q);
	while (q--){
		int x;
		scanf("%d", &x);
		printf("%d\n", (int)(upper_bound(A, A+N, x) - A));
	}


	return 0;
}