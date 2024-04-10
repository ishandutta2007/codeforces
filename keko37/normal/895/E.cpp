#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 100005;

int n, q, pot=1;
double a, b;

struct node {
	double val, a, b;
	bool prop;
	node () {
		val=0, a=1, b=0, prop=0;
	}
	node (double _val, double _a, double _b) {
		val=_val; a=_a; b=_b;
	}
} t[4*MAXN];

void propagate (int cvor, int low, int high) {
	t[cvor].prop=0;
	t[cvor].val=t[cvor].a*t[cvor].val+t[cvor].b*(high-low+1);
	if (cvor>=pot) {
		t[cvor].a=1;
		t[cvor].b=0;
		return;
	}
	if (t[cvor].a!=1) {
		t[cvor*2].a*=t[cvor].a;
		t[cvor*2].b*=t[cvor].a;
		t[cvor*2+1].a*=t[cvor].a;
		t[cvor*2+1].b*=t[cvor].a;
		t[cvor].a=1;
	}
	if (t[cvor].b!=0) {
		t[cvor*2].b+=t[cvor].b;
		t[cvor*2+1].b+=t[cvor].b;
		t[cvor].b=0;
	}
	t[cvor*2].prop=t[cvor*2+1].prop=1;
}

void update (int cvor, int from, int to, int low, int high) {
	if (t[cvor].prop) propagate(cvor, low, high);
	if (from<=low && high<=to) {
		t[cvor].a=a;
		t[cvor].b=b;
		propagate(cvor, low, high);
		return;
	}
	if (to<low || high<from) return;
	update(cvor*2, from, to, low, (low+high)/2);
	update(cvor*2+1, from, to, (low+high)/2+1, high);
	t[cvor].val=t[cvor*2].val+t[cvor*2+1].val;
}

double upit (int cvor, int from, int to, int low, int high) {
	if (t[cvor].prop) propagate(cvor, low, high);
	if (from<=low && high<=to) return t[cvor].val;
	if (to<low || high<from) return 0;
	return upit(cvor*2, from, to, low, (low+high)/2)+upit(cvor*2+1, from, to, (low+high)/2+1, high);
}

int main () {
	cin >> n >> q;
	while (pot<n) pot*=2;
	for (int i=0; i<n; i++) {
		scanf("%lf", &t[i+pot]);
	}
	for (int i=pot-1; i>0; i--) {
		t[i].val=t[i*2].val+t[i*2+1].val;
	}
	for (int i=0; i<q; i++) {
		int tip, l1, r1, l2, r2;
		scanf("%d", &tip);
		if (tip==1) {
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			double s1=upit(1, l1-1, r1-1, 0, pot-1);
			double s2=upit(1, l2-1, r2-1, 0, pot-1);
			a=((double) r1-l1)/(r1-l1+1);
			b=s2/(r1-l1+1)/(r2-l2+1);
			update(1, l1-1, r1-1, 0, pot-1);
			a=((double) r2-l2)/(r2-l2+1);
			b=s1/(r1-l1+1)/(r2-l2+1);
			update(1, l2-1, r2-1, 0, pot-1);
		} else {
			scanf("%d%d", &l1, &r1);
			printf("%.9f\n", upit(1, l1-1, r1-1, 0, pot-1));
		}
	}
	return 0;
}