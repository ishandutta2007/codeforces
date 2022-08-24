#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
char S[1000010];
int csLen;
char cs[100010];
int ansLen;
char ans[1000010];

int pos;
bool expr() {
	if (pos >= csLen) {
		return 0;
	}
	if (cs[pos] == 'p') {
		++pos;
		ans[ansLen++] = 'p';
		ans[ansLen++] = 'a';
		ans[ansLen++] = 'i';
		ans[ansLen++] = 'r';
		ans[ansLen++] = '<';
		if (!expr()) return 0;
		ans[ansLen++] = ',';
		if (!expr()) return 0;
		ans[ansLen++] = '>';
	} else {
		++pos;
		ans[ansLen++] = 'i';
		ans[ansLen++] = 'n';
		ans[ansLen++] = 't';
	}
	return 1;
}
bool solve() {
	if (csLen != N * 2 - 1) {
		return 0;
	}
	ansLen = 0;
	pos = 0;
	if (!expr()) return 0;
	if (pos != csLen) return 0;
	return 1;
}

int main() {
	int i;
	
	for (; gets(S); ) {
		N = atoi(S);
		gets(S);
		csLen = 0;
		for (i = 0; S[i]; ++i) {
			if (S[i] == 'p' || S[i] == 'n') {
				cs[csLen++] = S[i];
			}
		}
// cout<<"cs : ";pv(cs,cs+csLen);
		if (solve()) {
			ans[ansLen] = 0;
			puts(ans);
		} else {
			puts("Error occurred");
		}
	}
	
	return 0;
}