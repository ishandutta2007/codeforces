#include "bits/stdc++.h"
using namespace std;

struct Query {
	int id, l, r;
	
	bool operator< (const Query& o) const {
		return r < o.r;
	}
};

const int maxn = 1 << 20;
const int offs = (1 << 20) - 1;

struct SegTree {

	int X[2*maxn];

	SegTree(){}
	
	void insert(int pos, int val){
		pos += offs;
		X[pos] = val;
		while (pos > 1){
			pos /= 2;
			X[pos] = X[2*pos] ^ X[2*pos+1];
		}
	}
	
	int get(int l, int r, int node=1, int nl=1, int nr=maxn){
		if (l <= nl && nr <= r) return X[node];
		if (r < nl || nr < l) return 0;
		return get(l, r, 2*node, nl, (nl+nr)/2) ^ get(l, r, 2*node+1, (nl+nr)/2+1, nr);
	}

};



int N, M, A[1000005];
Query Q[1000005];

int Ans[1000005], E[1000005];

struct MyMap {

	int* X;
	int* Y;
	int P;
	
	MyMap() {
		X = new int[1000005];
		Y = new int[1000005];
		for (int i=1; i<=N; i++) X[i] = A[i];
		sort(X+1, X+N+1);
		int j=1;
		for (int i=2; i<=N; i++){
			if (X[i] != X[i-1]){
				j++;
				X[j] = X[i];
			}
		}
		P = j;
	}
	
	int& operator[] (int x){
		int l = lower_bound(X+1, X+P+1, x) - X;
		return Y[l];
	}
};

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%d", A+i);
		E[i] = E[i-1] ^ A[i];
	}
	
	scanf("%d", &M);
	for (int i=1; i<=M; i++){
		Q[i].id = i;
		scanf("%d%d", &Q[i].l, &Q[i].r);
	}
	
	sort(Q+1, Q+M+1);
	
	SegTree drvo;
	MyMap lastpos;
	
	int re = 0;
	
	for (int i=1; i<=M; i++){
		while (re < Q[i].r){
			re++;
			if (lastpos[A[re]] > 0){
				drvo.insert(lastpos[A[re]], 0);
			}
			drvo.insert(re, A[re]);
			lastpos[A[re]] = re;
		}
		Ans[Q[i].id] = drvo.get(Q[i].l, 1000000) ^ E[Q[i].r] ^ E[Q[i].l-1];
	}
	
	for (int i=1; i<=M; i++){
	    printf("%d\n", Ans[i]);
	}
	

	return 0;
}