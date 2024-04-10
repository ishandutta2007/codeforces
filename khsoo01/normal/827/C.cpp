#include<bits/stdc++.h>
using namespace std;
const int N = 100005, B = 13;

int n, a[N], b[B];
char ipt[N];

char atgc[5] = "ATGC";

struct segtree {
	int v[555555], lim;
	void init () {
		for(lim=1;lim<=2*N;lim<<=1);
	}
	void upd (int P, int V) {
		P += lim;
		while(P) {v[P] += V; P >>= 1;}
	}
	int get (int S, int E) {
		S += lim; E += lim;
		int ret = 0;
		while(S<=E) {
			if(S%2==1) ret += v[S++];
			if(E%2==0) ret += v[E--];
			S >>= 1; E >>= 1;
		}
		return ret;
	}
} seg[B][4];

void parse (int L, int A[]) {
	for(int i=1;i<=L;i++) for(int j=0;j<4;j++) {
		if(ipt[i] == atgc[j]) {A[i] = j; break;}
	}
}

int ind (int X, int P) {
	return (P%X)*(n/X+1)+(P/X);
}

int main()
{
	scanf("%s",ipt+1);
	n = strlen(ipt+1); parse(n, a);
	for(int i=1;i<=10;i++) for(int j=0;j<4;j++) seg[i][j].init();
	for(int k=1;k<=10;k++) {
		for(int i=1;i<=n;i++) {
			seg[k][a[i]].upd(ind(k, i), 1);
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		int T, E, S, L, A = 0;
		scanf("%d",&T);
		if(T == 1) {
			scanf("%d%s",&S,ipt+1);
			L = strlen(ipt+1); parse(L, b);
			if(a[S] == b[1]) continue;
			for(int i=1;i<=10;i++) {
				int I = ind(i, S);
				seg[i][a[S]].upd(I, -1);
				seg[i][b[1]].upd(I, 1);
			}
			a[S] = b[1];
		}
		else {
			scanf("%d%d%s",&S,&E,ipt+1);
			L = strlen(ipt+1); parse(L, b);
			for(int i=0;i<L;i++) {
				int CE = E - (E%L) + ((S+i)%L);
				if(CE > E) CE -= L;
				if(S+i > CE) continue;
				A += seg[L][b[i+1]].get(ind(L, S+i), ind(L, CE));
			}
			printf("%d\n",A);
		}
	}
}