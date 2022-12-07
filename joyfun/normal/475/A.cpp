#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int k;
string ans[6];

int x[35], y[35];

int main() {
	ans[0] = "+------------------------+";
	ans[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	ans[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	ans[3] = "|#.......................|";
	ans[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	ans[5] = "+------------------------+";
	x[0] = 1; y[0] = 1;
	x[1] = 2; y[1] = 1;
	x[2] = 3; y[2] = 1;
	x[3] = 4; y[3] = 1;
	int cnt = 3;
	for (int i = 4; i < 34; i++) {
		if ((i - 4) % 3 == 0) {
			x[i] = 1; y[i] = cnt;
		}
		if ((i - 4) % 3 == 1) {
			x[i] = 2; y[i] = cnt;
		}
		if ((i - 4) % 3 == 2) {
			x[i] = 4; y[i] = cnt;
			cnt += 2;
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		ans[x[i]][y[i]] = 'O';
	for (int i = 0; i < 6; i++)
		cout << ans[i] << endl;
	return 0;
}