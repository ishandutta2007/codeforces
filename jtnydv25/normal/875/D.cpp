#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

const int N = 2e5 + 10, logN = 20;

int OR[logN][N], floorlog[N], A[N], lft[N], rgt[N], n;
pii mx[logN][N];

pii max(const pii & P, const pii & Q){
	return (P > Q) ? P : Q;
}

pii P[N];

void getRMQ(){
	for(int i = n; i >= 1; i--){
		OR[0][i] = A[i];
		mx[0][i] = P[i];
		for(int j = 1; i + (1 << j) - 1 <= n; j++){
			OR[j][i] = OR[j - 1][i] | OR[j - 1][i + (1 << (j - 1))];
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
		}
	}
}

inline pii getMax(int i, int j){
	int k = floorlog[j - i + 1];
	return max(mx[k][i], mx[k][j - (1 << k) + 1]);
}

inline int getOR(int i, int j){
	int k = floorlog[j - i + 1];
	return OR[k][i] | OR[k][j - (1 << k) + 1];
}

inline int getLFT(int i){
	int lo = 1, hi = i;
	while(lo < hi){
		int mid = (lo + hi) >> 1;
		if(getOR(mid, i) == A[i] && getMax(mid, i) == P[i])
			hi = mid;
		else lo = mid + 1;
	}
	return i - lo + 1;
}

int main(){
	for(int i = 0; (1 << i) < N; i++){
		for(int j = (1 << i); j < (1 << (i + 1)) && j < N; j++)
			floorlog[j] = i;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", A + i);
		P[i] = {A[i], i};
	}

	getRMQ();

	for(int i = 1; i <= n; i++) lft[i] = getLFT(i);

	reverse(A + 1, A + n + 1);
	reverse(P + 1, P + n + 1);

	getRMQ();

	for(int i = 1; i <= n; i++){
		rgt[n - i + 1] = getLFT(i);
	}
	long long ans = (n * 1ll * (n + 1)) / 2;
	for(int i = 1; i <= n; i++){
		ans -= (lft[i] * 1ll * rgt[i]);
	}
	printf("%lld\n", ans);
}