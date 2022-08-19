#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x[1024], y[1024], c[1024];
int pts[1024];
int chull[1024], tp;
int chull_size;

int ans_l[1024], ans_r[1024], ans_len = 0;
void add_edge(int u, int v) {
	ans_l[ans_len] = u;
	ans_r[ans_len] = v;
	ans_len++;
}

void print_ans() {
	printf("%d\n", ans_len);
	for (int i = 0; i < ans_len; i++)
		printf("%d %d\n", ans_l[i], ans_r[i]);
}

bool ccw(int i, int j, int k) {
	return (x[i] * y[j] + x[j] * y[k] + x[k] * y[i]
		- x[j] * y[i] - x[k] * y[j] - x[i] * y[k]) > 0;
}

int pivot;
bool comp_by_pivot(int i, int j) {
	assert(i != pivot);
	assert(j != pivot);
	return ccw(pivot, i, j);
}

void run(int i, int j, int k, const vector<int> &inner, bool sep) {
	if (inner.size() == 0) {
		if (sep) {
			; // do nothing
		} else {
			add_edge(j, k);
		}
	} else {
		int pivot = -1;
		for (int p : inner) {
			if (pivot == -1 || ccw(j, p, pivot))
				pivot = p;
		}
		vector<int> j_inner, k_inner;
		for (int p : inner) if (p != pivot) {
			if (ccw(pivot, i, p))
				j_inner.push_back(p);
			else
				k_inner.push_back(p);
		}
		if (c[pivot] == c[i]) {
			run(j, pivot, i, j_inner, false);
			run(k, i, pivot, k_inner, true);
			if (!sep)
				add_edge(j, k);
		} else {
			run(i, j, pivot, j_inner, false);
			run(i, pivot, k, k_inner, sep);
		}
	}
}

void run(int i, int j, int k, bool sep) {
	assert(i != j && j != k && k != i);
	assert(ccw(i, j, k));
	vector<int> inner;
	for (int l = 0; l < n; l++)
		if (l != i && l != j && l != k && 
				ccw(i, j, l) && ccw(j, k, l) && ccw(k, i, l)) {
			inner.push_back(l);
		}
	/*
	printf("%d %d %d\n", i, j, k);
	printf("size %d\n", (int)inner.size());
	*/

	run(i, j, k, inner, sep);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
	}

	if (n == 1) {
		printf("0\n");
	} else if (n == 2) {
		if (c[0] == c[1]) {
			printf("1\n");
			printf("0 1\n");
		} else {
			printf("0\n");
		}
	} else { // n >= 3
		// Compute the pivot for convex hull
		pivot = 0;
		for (int i = 1; i < n; i++)
			if (x[i] < x[pivot] || 
					(x[i] == x[pivot] && y[i] < y[pivot]))
				pivot = i;

		// Sort by pivot point
		for (int i = 0; i < n - 1; i++)
			pts[i] = (i < pivot ? i : i + 1);
		sort(pts, pts + n - 1, comp_by_pivot);

		// Do the Graham algorithm
		chull[0] = pivot; tp = 0;
		for (int i = 0; i < n - 1; i++) {
			int cur = pts[i];
			while (tp >= 1 && (ccw(chull[tp - 1], chull[tp], cur) == false))
				tp--;
			chull[++tp] = cur;
		}
		chull_size = tp + 1;
		/*
		for (int i = 0; i < chull_size; i++)
			printf("%d ", chull[i]);
		printf("\n");
		*/

		int num_change = 0;
		for (int i = 0; i < chull_size; i++)
			if (c[chull[i]] != c[chull[(i + 1) % chull_size]])
				num_change++;
		// printf("%d\n", num_change);

		if (num_change == 0) {
			int c_chull = c[chull[0]];

			// choose a center_pivot point with different color
			int center_pivot = -1;
			for (int i = 0; i < n; i++)
				if (c[i] != c_chull) {
					center_pivot = i;
					break;
				}

			if (center_pivot == -1) { // all of same color
				// just make a spike
				printf("%d\n", n - 1);
				for (int i = 0; i < n - 1; i++)
					printf("%d %d\n", pivot, pts[i]);
			} else {
				// run the recursive triangle construction with center_pivot
				for (int i = 0; i < chull_size - 1; i++) {
					run(center_pivot, chull[i], chull[i + 1], false);
				}
				run(center_pivot, chull[chull_size - 1], chull[0], true);
				print_ans();
			}
		} else if (num_change == 2) {
			int p1 = -1;
			for (int i = 1; i < chull_size; i++)
				if (c[chull[i - 1]] != c[chull[i]]) {
					p1 = i;
					break;
				}
			assert(p1 >= 1 && p1 < chull_size);
			rotate(chull, chull + p1, chull + chull_size);
			// for (int i = 0; i < chull_size; i++)
			//	printf("%d ", chull[i]);
			// printf("\n");
			int p2 = -1;
			for (int i = 1; i < chull_size; i++)
				if (c[chull[i - 1]] != c[chull[i]]) {
					p2 = i;
					break;
				}
			// printf("ans\n");
			// printf("%d\n", p2);
			for (int i = 0; i < p2 - 1; i++) {
				run(chull[p2], chull[i], chull[i + 1], false);
				// printf("test\n");
				// print_ans();
			}
			for (int i = p2; i < chull_size - 1; i++) {
				run(chull[0], chull[i], chull[i + 1], false);
				// printf("test\n");
				// print_ans();
			}
			print_ans();
		} else {
			assert(num_change % 2 != 1); // it can never be odd
			printf("Impossible\n");
		}
	}

	return 0;
}