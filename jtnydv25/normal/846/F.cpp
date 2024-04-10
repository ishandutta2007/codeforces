#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
int P[N], A[N], S[N];
int main(){
	int n; scanf("%d", &(n));
	long long sm = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		P[i] = S[A[i]];
		S[A[i]] = i;
		sm += 2 * (i - P[i]) * 1ll * (n - i + 1) - 1;
	}
	printf("%.10lf\n", sm / (n * 1ll * n * 1.0));
}