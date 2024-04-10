#include<bits/stdc++.h>
using namespace std;

int n;

int query (int I, int C) {
	printf("1 %d %d ", C, I);
	for(int i=1,j=0;i<=n && j<C;i++) {
		if(i == I) continue;
		printf("%d ", i);
		j++;
	}
	puts("");
	fflush(stdout);
	int R;
	scanf("%d",&R);
	return R;
}

void solve () {
	scanf("%d",&n);
	int D = query(1, n-1);
	int S = 1, E = n-1;
	while(S<E) {
		int M = (S+E)/2;
		int X = query(1, M);
		X < D ? S = M+1 : E = M;
	}
	printf("-1 %d\n", query(1+S, n-1));
	fflush(stdout);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}