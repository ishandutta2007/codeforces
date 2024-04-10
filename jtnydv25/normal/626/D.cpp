#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld double

const int N = 5005;

int A[N], numD[N], prefD[N];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		for(int j = 1; j < i; j++){
			numD[abs(A[i] - A[j])]++;
		}
	}
	for(int i = 1;i < N; i++) prefD[i] = prefD[i - 1] + numD[i];

	ll ways = (prefD[N - 1] * 1ll * prefD[N - 1] * 1ll * prefD[N - 1]);
	ll valid = 0;
	for(int d1 = 1; d1 < N; d1++)
		for(int d2 = 1; d1 + d2 < N; d2++){
			// d3 > d1 + d2
			valid += numD[d1] * 1ll * numD[d2] * 1ll * (prefD[N - 1] - prefD[d1 + d2]);
		}
	// cerr << valid << " " << 
	printf("%.17lf\n", ((ld)valid) / ((ld)ways));
}