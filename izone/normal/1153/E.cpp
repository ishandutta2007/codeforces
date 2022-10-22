#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int swapped;

void Answer(int bx, int by, int ex, int ey) {
	if (swapped) {
		swap(bx, by);
		swap(ex, ey);
	}

	printf("! %d %d %d %d\n", bx, by, ex, ey);
	fflush(stdout);
}
int Query(int bx, int by, int ex, int ey) {
	if (swapped) {
		swap(bx, by);
		swap(ex, ey);
	}
	printf("? %d %d %d %d\n", bx, by, ex, ey);
	fflush(stdout);
	int a;
	scanf("%d", &a);
	return a;
}
int X[1010], Y[1010];

int n;

bool Do() {
	int i;
	vector<int>A;
	for (i = 1; i <= n && A.size() < 2; i++) {
		if (swapped && i == n) {
			A.push_back(i);
			break;
		}
		X[i] = Query(i, 1, i, n);
		if (X[i] % 2) {
			A.push_back(i);
		}
	}
	if (A.empty())return false;
	int b = 1, e = n, mid, r, B[2];
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Query(A[0], 1, A[0], mid) % 2) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	B[0] = r;
	b = 1, e = n;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Query(A[1], 1, A[1], mid) % 2) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	B[1] = r;
	Answer(A[0], B[0], A[1], B[1]);
}

int main() {
	int i;
	scanf("%d", &n);

	if (!Do()) {
		swapped = 1;
		Do();
	}

}