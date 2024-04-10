#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	void read() {scanf("%lf%lf", &x, &y);}
	Point operator - (const Point& c) const {
		return Point(x - c.x, y - c.y);
	}
};

typedef Point Vector;
double Dot(Vector A, Vector B) {return A.x * B.x + A.y * B.y;}
double Length(Vector A) {return sqrt(Dot(A, A));}
double Cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}
const int N = 1005;
int n;
Point p[N];

double dtl(Point P, Point A, Point B) {
	Vector v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2)) / Length(v1);
}

int main() {
	scanf("%d", &n);
	double ans = 1e18;
	for (int i = 0; i < n; i++) p[i].read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int f = -1; f <= 1; f++) {
				if (f == 0) continue;
				int k = (i + f + n) % n;
				if (k != j) ans = min(ans, dtl(p[k], p[i], p[j]));
			}
		}
	}
	printf("%.12f\n", ans / 2);
	return 0;
}