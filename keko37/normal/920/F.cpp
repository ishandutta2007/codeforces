#include<iostream>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int n, m, ofs=1;
int d[MAXN];

struct node {
	llint sum, br;
	node () {
		sum=br=0;
	}
	node (llint _sum, llint _br) {
		sum=_sum; br=_br;
	}
} t[2*MAXN];

void precompute () {
	for (int i=1; i<MAXN; i++) {
		for (int j=i; j<MAXN; j+=i) {
			d[j]++;
		}
	}
}

node spoji (node a, node b) {
	return node(a.sum+b.sum, a.br+b.br);
}

void update (int cvor, int from, int to, int low, int high) {
	if (to<low || high<from) return;
	if (low==high) {
		t[cvor].sum=d[t[cvor].sum];
		if (t[cvor].sum<=2) t[cvor].br=0;
		return;
	}
	if (t[cvor*2].br) update(cvor*2, from, to, low, (low+high)/2);
	if (t[cvor*2+1].br) update(cvor*2+1, from, to, (low+high)/2+1, high);
	t[cvor]=spoji(t[cvor*2], t[cvor*2+1]);
}

llint upit (int cvor, int from, int to, int low, int high) {
	if (from<=low && high<=to) return t[cvor].sum;
	if (to<low || high<from) return 0;
	return upit(cvor*2, from, to, low, (low+high)/2)+upit(cvor*2+1, from, to, (low+high)/2+1, high);
}


int main () {
	precompute();
	cin >> n >> m;
	while (ofs<n) ofs*=2;
	for (int i=0; i<n; i++) {
		scanf("%I64d", &t[ofs+i].sum);
		if (t[ofs+i].sum>2) t[ofs+i].br=1;
	}
	for (int i=ofs-1; i>0; i--) {
		t[i]=spoji(t[i*2], t[i*2+1]);
	}
	for (int i=0; i<m; i++) {
		int tip, a, b;
		scanf("%d%d%d", &tip, &a, &b);
		a--; b--;
		if (tip==1) {
			update(1, a, b, 0, ofs-1);
		} else {
			printf("%I64d\n", upit(1, a, b, 0, ofs-1));
		}
	}
	return 0;
}