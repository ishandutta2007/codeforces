#include<bits/stdc++.h>
using namespace std;

const int N = 300005;
int n, m, a[N];

bool can (int X) {
	int C = 0;
	for(int i=1;i<=n;i++) {
		while(C < m) {
			int D = (a[i] <= C ? C - a[i] : m + C - a[i]);
			if(D <= X) break;
			else C++;
		}
		if(C == m) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int S = 0, E = m;
	while(S<E) {
		int M = (S+E)/2;
		can(M) ? E = M : S = M+1;
	}
	printf("%d\n", S);
}