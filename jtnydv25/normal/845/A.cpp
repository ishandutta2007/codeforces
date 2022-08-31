#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 1e6 + 10;
int A[N];
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		sd(n);
		for(int i = 1; i <= 2 * n; i++) sd(A[i]);
		sort(A + 1, A + 2 * n + 1);
		if(A[n] < A[n + 1]) printf("YES");
		else printf("NO");
	}
}