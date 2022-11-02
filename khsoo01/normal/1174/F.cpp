#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, chi[N];
vector<int> adj[N];

int query (char T, int I) {
	printf("%c %d\n", T, I);
	fflush(stdout);
	int X;
	scanf("%d",&X);
	return X;
}

void calc (int C, int P) {
	chi[C] = 1;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		calc(T, C);
		chi[C] += chi[T];
	}
}

int solve (int R, int D) {
	if(D == 0) return R;
	int L = R;
	vector<int> V;
	while(true) {
		V.push_back(L);
		int NL = 0;
		for(auto &T : adj[L]) {
			if(chi[L] > chi[T] && chi[T] > chi[NL]) NL = T;
		}
		if(!NL) break;
		L = NL;
	}
	int X = query('d', L);
	int ND = ((D+X)-(int)V.size()+1)/2;
	int NR = V[D-ND];
	if(ND == 0) return NR;
	return solve(query('s', NR), ND-1);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	calc(1, 0);
	printf("! %d\n", solve(1, query('d', 1)));
}