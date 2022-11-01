#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

long long n;
int k;
long long nums[100];

long long precount[101][100000];

long long count(int pos, long long curn) {
	if (curn == 0) return 0;
	if (curn < 100000 && precount[pos][curn] != -1)
		return precount[pos][curn];
	long long res = curn;
	for (int next1 = pos; next1 < k; next1++) {
		res -= count(next1 + 1, curn / nums[next1]);
	}
	if (curn < 100000)
		precount[pos][curn] = res;
	return res;
}

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> nums[i];
		if (nums[i] == 1) {
			cout << 0 << endl;
			return 0;
		}
	}
	sort(nums, nums+k);
	reverse(nums, nums+k);
	memset(precount, -1, sizeof(precount));
	cout << count(0, n);
	return 0;
}