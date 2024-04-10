#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;
	int pl, pr, vl, vr, k;
	v.push_back(4);
	v.push_back(7);
	scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
	for (int i = 0; v[i] < 100000000; i++) {
		v.push_back(v[i] * 10 + 4);
		v.push_back(v[i] * 10 + 7);
	}
	v.push_back(-1);
	v.push_back(1000000001);
	sort(v.begin(), v.end());
	double res = 0.0;
	for (int i = 0; i < (int)v.size() - k - 1; i++) {
		int al = v[i] + 1;
		int ar = v[i+1];
		int bl = v[i+k] ;
		int br = v[i+k+1] - 1;
		res += max(0, min(ar, pr) - max(al, pl) + 1) / double(pr - pl + 1) * max(0, min(br, vr) - max(bl, vl) + 1) / double(vr - vl + 1);
		res += max(0, min(br, pr) - max(bl, pl) + 1) / double(pr - pl + 1) * max(0, min(ar, vr) - max(al, vl) + 1) / double(vr - vl + 1);
		if (k == 1) {
			res -= max(0, min(ar, pr) - max(ar, pl) + 1) / double(pr - pl + 1) * max(0, min(ar, vr) - max(ar, vl) + 1) / double(vr - vl + 1);
		}
	}
	printf("%.9lf\n", res);
	return 0;
}