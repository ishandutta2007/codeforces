#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n;
char str[400][100];
char trans[400][100];

void tran1(char * dest, char * src) {
	int l = strlen(src);
	int j = 0;
	for (int i = 0; i < l; ++i) {
		if (src[i] == 'u') {
			dest[j++] = 'o';
			dest[j++] = 'o';
		}
		else dest[j++] = src[i];
	}
	dest[j] = '\0';
}

void tran2(char * dest, char * src) {
	int l = strlen(src);
	int j = 0;
	for (int i = 0; i < l; ++i) {
		if (i < l - 1 && src[i] == 'k' && src[i + 1] == 'h') {
			while (j > 0 && dest[j - 1] == 'k') --j;
			continue;
		}
		dest[j++] = src[i];
	}
	dest[j] = '\0';
}

struct cmp {
	bool operator()(char * str1, char * str2) {
		return strcmp(str1, str2) < 0;
	}
};

set<char *, cmp> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		tran1(trans[i], str[i]);
		tran2(str[i], trans[i]);
		mp.insert(str[i]);
	}
	printf("%d\n", (int)mp.size());
	return 0;
}