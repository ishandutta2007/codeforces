#include<iostream>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 400005;
const int LIM = 20;

llint n, cnt=1, sol;
llint par[MAXN], nxt[MAXN] [LIM], sum[MAXN] [LIM], val[MAXN];

void add_node (int r, llint w) {
	cnt++;
	par[cnt]=r;
	val[cnt]=w;
	if (val[r]>=val[cnt]) {
		nxt[cnt] [0]=r;
	} else {
		int curr=r;
		for (int i=LIM-1; i>=0; i--) {
			if (nxt[curr] [i]!=0 && val[nxt[curr] [i]] < val[cnt]) {
				curr=nxt[curr] [i];
			}
		}
		nxt[cnt] [0]=nxt[curr] [0];
	}
	sum[cnt] [0]=val[cnt];
	for (int i=1; i<LIM; i++) {
		nxt[cnt] [i]=nxt[nxt[cnt] [i-1]] [i-1];
		sum[cnt] [i]=sum[cnt] [i-1]+sum[nxt[cnt] [i-1]] [i-1];
	}
}

int upit (int x, llint w) {
	if (val[x]>w) return 0;
	int res=0, curr=x;
	for (int i=LIM-1; i>=0; i--) {
		if (nxt[curr] [i]!=0 && sum[curr] [i]<=w) {
			res+=(1<<i);
			w-=sum[curr] [i];
			curr=nxt[curr] [i];
		}
	}
	if (val[curr]<=w) res++;
	return res;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		llint tip, p, q;
		scanf("%I64d%I64d%I64d", &tip, &p, &q);
		if (tip==1) {
			add_node(p^sol, q^sol);
		} else {
			sol=upit(p^sol, q^sol);
			printf("%I64d\n", sol);
		}
	}
	return 0;
}