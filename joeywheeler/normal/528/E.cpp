#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define EPS 1e-7

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

typedef complex<double> p;

p a[3005], b[3005];
int n;

double cross(p s, p t) {return imag(conj(s) * t);}

p is(p s, p t, p q, p r) {
	double d1 = cross(q-s, t-s);
	double d2 = cross(r-s, t-s);
	return (d1 * r - d2 * q) / (d1 - d2);
}

double calc(int m) {
	if (arg(b[m]-a[m]) < -EPS) swap(b[m],a[m]);
	else if (abs(arg(b[m]-a[m])) < EPS || abs(arg(b[m]-a[m])) > M_PI-EPS) {
		if (real(a[m]) > real(b[m])) swap(b[m],a[m]);
	}
	vector<double> IS(n);
	vector<p> ISP(n);
	vector<double> AN(n);
	vector<pair<double,int>> SAN; SAN.reserve(n-1);
	vector<int> ANG(n);
	vector<int> o; o.reserve(n-1);
	FO(i,0,n) if (i != m) {
		ISP[i] = is(a[m],b[m],a[i],b[i]);
		IS[i] = ((ISP[i]-a[m]) / (b[m]-a[m])).real();
		double an = arg((b[m]-a[m]) / (b[i]-a[i]));
		if (an < 0) an += M_PI;
		SAN.push_back({an,i});
		o.push_back(i);
	}
	sort(SAN.begin(), SAN.end());
	FO(i,0,n-1) ANG[SAN[i].second] = i;
	sort(o.begin(), o.end(), [&](int x, int y){return IS[x] < IS[y];});
	double res = 0;
	int ps = 0;
	FO(I,0,sz(o)-1) {
		int i = o[I], j = o[I+1];
		double val = cross(ISP[i], ISP[j]) / 2;
		i = ANG[i];
		ps += n-2-2*i;
		res += ps * val;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	FO(i,0,n) {
		double A, B, C;
		scanf("%lf %lf %lf", &A, &B, &C);
		if (fabs(B) > EPS) {
			a[i] = p(0,C/B);
			b[i] = p(1,(C-A)/B);
		} else {
			a[i] = p(C/A,0);
			b[i] = p((C-B)/A,1);
		}
	}
	double res = 0;
	FO(i,0,n) res += 6 * calc(i) / n / (n-1) / (n-2);
	printf("%.10lf\n", abs(res));
}