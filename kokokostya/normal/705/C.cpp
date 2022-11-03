#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector< queue<int> > arr(n);
	int now = 0;
	vector<int> tim;
	int sum = 0;
	int k = 0;
	for (int i = 0; i < q; i++) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			sum++;
			tim.push_back(x);
			arr[x - 1].push(k);
			k++;
		}
		else
			if (t == 2) {
				while (!arr[x - 1].empty()) {
					if (tim[arr[x - 1].front()]) {
						sum--;
						tim[arr[x - 1].front()] = 0;
					}
					arr[x - 1].pop();
				}
			}
			else {
				while (now < x) {
					if (tim[now]) {
						sum--;
						tim[now] = 0;
					}
					now++;
				}
			}
		printf("%d\n", sum);
	}

	return 0;
}