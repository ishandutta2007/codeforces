#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 223456;

int n, f, num[maxN], cnt[maxN], sg[maxN], mark[maxN];
vector<int> v;

bitset<200001> sp, way[66];

int a, b, c;

int main() {
	scanf("%d%d", &n, &f);
	for (int i = 2; i <= 200000; i++) {
		num[i] = i;
		cnt[i] = 0;
	}
	for (int i = 2; i <= 200000; i++) if (cnt[i] == 0) {
			for (int j = i; j <= 200000; j += i) {
				while (num[j] % i == 0) {
					num[j] /= i;
					cnt[j]++;
				}
			}
		}

	cnt[f] = 3;
	for (int i = 2; i <= 200000; i++) if (cnt[i] <= 2) {
			sp[i] = 1;
		}
	for (int i = 0; i <= 200000; i++) {
		while (way[sg[i]][i]) ++sg[i];
		way[sg[i]] |= sp << i;
	}
	int w = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		w ^= sg[b - a - 1] ^ sg[c - b - 1];
	}
	puts(w ? "Alice" : "Bob");
	puts(w ? "Bob" : "Alice");
}