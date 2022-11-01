#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <vector>
using namespace std;

template <typename T>
T next_int() {
	T x = 0, p = 1;
	char ch;
	do { ch = getchar(); } while(ch <= ' ') ;
	if(ch == '-') {
		p = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return p * x;
}

const int max_int = (int)1e9 + 227 + 1;
const int max_n = (int)1e6 + 227 + 1;
const int mod = (int)1e9 + 7;

long long Sqrt(long long a) {
	long long l = 0;
	long long r = (int)1e9;
	while(r - l > 1) {
		long long c = (l + r) / 2;
		if(c * c <= a) l = c; else r = c;
	}

	if(r * r == a) return r; else 
	if(l * l == a) return l; else return -1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen("bomb.txt", "w", stdout);

	long long a[2][2] = {{0, 0}, {0, 0}};
	for(int i = 0; i < 2; i++) 
		for(int j = 0; j < 2; j++)
			a[i][j] = next_int<int>();

	if(a[0][0] + a[0][1] + a[1][1] + a[1][0] == 0) {
		puts("0");
		return 0;
	}

	if(a[0][1] + a[1][1] + a[1][0] == 0) {
		string ans = "";
		while(a[0][0] > 0) {
			a[0][0] -= ans.size();
			ans += '0';
		}

		if(a[0][0]) {
			puts("Impossible");
			return 0;
		}

		cout << ans << "\n";
		return 0;
	}

	if(a[0][1] + a[0][0] + a[1][0] == 0) {
		string ans = "";
		while(a[1][1] > 0) {
			a[1][1] -= ans.size();
			ans += '1';
		}

		if(a[1][1]) {
			puts("Impossible");
			return 0;
		}

		cout << ans << "\n";
		return 0;
	}

	if(Sqrt(1 + 8 * a[1][1]) == -1 || Sqrt(1 + 8 * a[0][0]) == -1 || (1 + Sqrt(1 + 8LL * a[1][1])) % 2 || (1 + Sqrt(1 + 8LL * a[0][0])) % 2) {
		puts("Impossible");
		return 0;
	}

	long long n = (1 + Sqrt(1 + 8LL * a[0][0])) / 2; // 0
	long long m = (1 + Sqrt(1 + 8LL * a[1][1])) / 2; // 1

	if(n * m != a[0][1] + a[1][0]) {
		puts("Impossible");
		return 0;
	}

	long long A = n * m; // a[1][0]
	long long B = 0; // a[0][1]
	int it = 0;
	while(B + n <= a[0][1]) {
		B += n;
		A -= n;
		it++;
	}

	int p = (a[0][1] - B);

	for(int i = 0; i < m - it - (bool)(p); i++) cout << "1";
	for(int i = 0; i < p; i++) cout << "0";
	if(p) cout << "1";
	for(int i = 0; i < n - p; i++) cout << "0";
	while(it--) cout << "1";
	puts(""); 
}