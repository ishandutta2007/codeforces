#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const llint R = 1000000;

int n, cnt;
llint x[2*MAXN], y[2*MAXN], lef[2*MAXN], rig[2*MAXN];
llint sign[2*MAXN];
queue <int> q;

llint kvad (llint x) {
	return x*x;
}

bool moze (int a, int b) {
	return kvad(x[a]*sign[a] + x[b]*sign[b]) + kvad(y[a]*sign[a] + y[b]*sign[b]) <= R*R;
}

void rjesi (int a, int b, int c) {
	int v1, v2, v3;
	if (moze(a, b)) {
		v1 = a; v2 = b; v3 = c;
	} else {
		sign[b] *= -1;
		if (moze(a, b)) {
			v1 = a; v2 = b; v3 = c;
		} else {
			if (moze(a, c)) {
				v1 = a; v2 = c; v3 = b;
			} else {
				sign[c] *= -1;
				if (moze(a, c)) {
					v1 = a; v2 = c; v3 = b;
				} else {
					v3 = a;
					if (moze(b, c)) {
						v1 = b; v2 = c;
					} else {
						sign[c] *= -1;
						v1 = b; v2= c;
					}
				}
			}
		}
	}
	q.push(v3);
	cnt++;
	q.push(cnt);
	x[cnt] = x[v1]*sign[v1] + x[v2]*sign[v2];
	y[cnt] = y[v1]*sign[v1] + y[v2]*sign[v2];
	sign[cnt] = 1;
	lef[cnt] = v1;
	rig[cnt] = v2;
}

void calc () {
	for (int i=0; i<n-2; i++) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		int c = q.front(); q.pop();
		rjesi(a, b, c);
	}
	if (n>=2) {
		int aa = q.front(); q.pop();
		int bb = q.front(); q.pop();
		if (!moze(aa, bb)) sign[bb] *= -1;
	}
}

void sredi () {
	for (int i=cnt; i>=1; i--) {
		sign[lef[i]] *= sign[i];
		sign[rig[i]] *= sign[i];
	}
}

int main () {
	cin >> n;
	cnt = n;
	for (int i=1; i<=n; i++) {
		scanf("%I64d%I64d", &x[i], &y[i]);
		sign[i] = 1;
		q.push(i);
	}
	calc();
	sredi();
	for (int i=1; i<=n; i++) {
		printf("%I64d ", sign[i]);
	}
	return 0;
}