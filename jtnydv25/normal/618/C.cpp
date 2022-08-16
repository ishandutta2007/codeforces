#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int x[N], y[N], perm[N];
double X[N], Y[N];

bool cmp(int i, int j){
	return X[i] < X[j];
}
const double EPS = 1e-4;
int main(){
	int n;
	srand(time(NULL));
	double ang = rand();
	scanf("%d", &n);
	for(int i = 1;i <= n; i++){
		scanf("%d %d", &x[i], &y[i]);
		X[i] = x[i] * cos(ang) + y[i] * sin(ang);
		Y[i] = y[i] * cos(ang) - x[i] * sin(ang);
		perm[i] = i;
	}

	sort(perm + 1, perm + n + 1, cmp);
	for(int i = 1; i <= n - 2; i++){
		double a = x[perm[i + 1]] - x[perm[i]], b = y[perm[i + 1]] - y[perm[i]];
		double _a = x[perm[i + 2]] - x[perm[i + 1]], _b = y[perm[i + 2]] - y[perm[i + 1]];

		if(abs(a * _b - b * _a) >= EPS){
			cout << perm[i] << " " << perm[i + 1] << " " << perm[i + 2] << endl;
			return 0;
		}
	}
}