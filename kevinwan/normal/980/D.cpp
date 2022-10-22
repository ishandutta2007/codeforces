#include <bits/stdc++.h>
using namespace std;
int nums[5000], ans[5001];
int f(int x) {
	set<int> s;
	if (x < 0) {
		s.insert(-1);
		x *= -1;
	}
	for (int i = 2; i*i <= x; i++) {
		while (x%i == 0) {
			x /= i;
			if(s.find(i)==s.end())s.insert(i);
			else s.erase(i);
		}
	}
	for (int k : s)x *= k;
	return x;
}
map<int, int> idk;
bitset<5001> hail;
int main() {
	int n, i, j, id = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", nums + i);
		if(nums[i]==0)continue;
		nums[i] = f(nums[i]);
		if (idk[nums[i]] == 0)idk[nums[i]] = id++;
		nums[i] = idk[nums[i]];
	}
	for (i = 0; i < n; i++) {
		hail.reset();
		int kkk = 0;
		for (j = i; j < n; j++) {
			if (nums[j] && (!hail[nums[j]]))kkk++;
			hail[nums[j]] = 1;
			ans[kkk]++;
		}
	}
	printf("%d ", ans[0] + ans[1]);
	for (i = 2; i <= n; i++)printf("%d ", ans[i]);
}