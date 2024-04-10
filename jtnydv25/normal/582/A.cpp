#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define pb push_back
#define vi vector<int>
const int N = 505;
int G[N * N], A[N];
map<int, int> myp;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n * n; i++){
		sd(G[i]); myp[G[i]]++;
	}
	sort(G + 1, G + n * n + 1);
	int r = n * n;
	for(int i = 1; i <= n; i++){
		while(r >= 1 && (!myp[G[r]])) r--;
		printf("%d ", G[r]);
		A[i] = G[r--];
		for(int j = 1; j < i; j++) myp[__gcd(A[i], A[j])] -= 2;
		myp[A[i]]--;	
	}
}