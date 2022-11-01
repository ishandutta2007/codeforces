#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string readString() {
	static char str[1000000];
	scanf("%s", str);
	return str;
}

int main(void) {
	string num1 = readString();
	string num2 = readString();
	int n = (int) max(num1.size(), num2.size());
	vector<int> v1(n);
	vector<int> v2(n);
	transform(num1.rbegin(), num1.rend(), v1.begin(), [](char ch) {return ch - '0';});
	transform(num2.rbegin(), num2.rend(), v2.begin(), [](char ch) {return ch - '0';});
	int k = n;
	while (k > 0) {
		--k;
		int mn = min(v1[k], v2[k]);
		v1[k] -= mn;
		v2[k] -= mn;
		if (v1[k] >= 2) {
			printf(">\n");
			return 0;
		}
		if (v2[k] >= 2) {
			printf("<\n");
			return 0;
		}
		if (v1[k] == v2[k])
			continue;
		if (k < 2) {
			printf("%c\n", (v1[k] == 1) ? '>' : '<');
			return 0;
		}
		if (v1[k] == 1) {
			v1[k-1] += 1;
			v1[k-2] += 1;
			v1[k] -= 1;
		}
		if (v2[k] == 1) {
			v2[k-1] += 1;
			v2[k-2] += 1;
			v2[k] -= 1;
		}
	}
	printf("=\n");
	return 0;
}