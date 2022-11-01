#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
using namespace std;

typedef complex<double> point;


int N, K;
double eps;
vector<point> objects;

inline point readPoint() {
	double x, y;
	scanf("%lf%lf", &x, &y);
	return point(x, y);
}

int main(void) {
	scanf("%d%d%lf", &N, &K, &eps);
	eps /= 1000.0;
	point center = readPoint();
	objects.reserve(N);
	for (int i = 0; i < N; i++) {
		objects.push_back(readPoint() - center);
	}
	double l = 0.0;
	double r = 4000.0;
	while (r - l > 1e-8) {
		double m = (r + l) / 2.0;
		vector<double> prob(K + 1, 0.0);
		prob[0] = 1.0;
		for (int i = 0; i < N; i++) {
			double t =min(1.0,  exp(1.0 - norm(objects[i])/m/m));
			for (int j = K; j != 0; j--) {
				prob[j] += prob[j-1] * t;
				prob[j-1] *= 1 - t;
			}
		}
		if (1.0 - prob[K] > eps) {
			l = m;
		} else {
			r = m;
		}
	}
	printf("%.6lf\n", r);
	return 0;
}