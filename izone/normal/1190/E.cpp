#include<cstdio>
#include<algorithm>
#include<cmath>
#define SZ 524288
using namespace std;
struct point {
	double x, y;
	point operator +(const point &p)const {
		return { x + p.x,y + p.y };
	}
	point operator-(const point &p)const {
		return { x - p.x,y - p.y };
	}
	point operator *(const double &k)const {
		return { x*k,y*k };
	}
	point Rotate() {
		return { -y,x };
	}
	double Len() {
		return sqrt(x*x + y * y);
	}

}w[101000], O;
struct Order {
	double z;
	int num;
	bool operator<(const Order &p)const {
		return z < p.z;
	}
}U[201000];

int n, m;

struct Range {
	int b, e, d;
	bool operator<(const Range &p)const {
		return d < p.d;
	}
}P[101000];

int IT[SZ + SZ];

void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = max(IT[a * 2], IT[a * 2 + 1]);
	}
}
int Get(int b, int e) {
	int r = -1;
	b += SZ, e += SZ;
	while (b <= e) {
		r = max(r, max(IT[b], IT[e]));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}

struct AA {
	int b, e;
	bool operator <(const AA &p)const {
		return b < p.b;
	}
}T[101000];

int C[101000][20];

bool Pos(double R) {
	int i, j, pv = 0;
	const double PI = acos(-1.0);
	for (i = 0; i < n; i++) {
		double d = w[i].Len();
		if (d <= R)return false;
		double An = atan2(w[i].y, w[i].x);
		double An2 = acos(R / w[i].Len());
		double A1 = An - An2, A2 = An + An2;
		while (A1 < -PI)A1 += PI + PI;
		while (A1 > PI)A1 -= PI + PI;
		while (A2 < -PI)A2 += PI + PI;
		while (A2 > PI)A2 -= PI + PI;
		U[i] = { A1,i };
		U[i+n] = { A2,i+n };
	}
	sort(U, U + n + n);
	for (i = 0; i < n + n; i++) {
		if (U[i].num < n)P[U[i].num].b = i;
		else P[U[i].num - n].e = i;
	}
	for (i = 0; i < n; i++) {
		P[i].d = P[i].e - P[i].b;
		if (P[i].d < 0)P[i].d += n + n;
	}
	sort(P, P + n);
	for (i = 0; i < SZ + SZ; i++)IT[i] = -1;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		int b = P[i].b, e = P[i].e;
		if (b > e)e += n + n;
		if (Get(b, e) > b) {
		}
		else {
			Put(e, b);
			if (e < n + n) {
				Put(e + n + n, b + n + n);
			}
			T[cnt++] = { P[i].b,P[i].e };
		}
	}
	sort(T, T + cnt);

	pv = 0;
	for (i = 0; i < cnt; i++) {
		if (pv <= i)pv = i + 1;
		int ee = T[i].e;
		if (ee < T[i].b)ee += n + n;
		while (pv < cnt + i) {
			AA z = T[pv%cnt];
			while (z.b < T[i].b)z.b += n + n;
			if (z.b > ee)break;
			pv++;
		}
		C[i][0] = pv - i;
	}

	for (i = 0; i < 17; i++) {
		for (j = 0; j < cnt; j++) {
			C[j][i + 1] = min(C[j][i] + C[(j + C[j][i]) % cnt][i], cnt + 1);
		}
	}
	for (i = 0; i < cnt; i++) {
		int s = 0;
		for (j = 0; j < 17; j++) {
			if ((m >> j) & 1) {
				s += C[(i + s) % cnt][j];
			}
		}
		if (s >= cnt)return true;
	}
	return false;

}
int main() {
	double b = 0.0, e = 1e6, mid;
	int i;
	scanf("%d%d", &n,&m);
	for (i = 0; i < n; i++) {
		scanf("%lf%lf", &w[i].x, &w[i].y);
		if (w[i].x == 0 && w[i].y == 0) {
			puts("0.000");
			return 0;
		}
		e = min(e, sqrt(w[i].x*w[i].x + w[i].y*w[i].y));
	}
	for (i = 0; i < 40; i++) {
		mid = (b + e)*0.5;
		if (Pos(mid)) b = mid;
		else e = mid;
	}
	printf("%.15f\n", (b+e)*0.5);
}