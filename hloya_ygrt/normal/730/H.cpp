// In the name of God
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <assert.h>
#include <bitset>
#define sqr(a) (a)*(a)
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
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

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e5 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-8;

long long bin_pow(long long a, long long b) {
	if(!b) return 1;
	long long ans = bin_pow(a, b / 2);
	ans = ans * ans % MOD;
	if(b % 2) ans = ans * a % MOD;
	return ans;
}

int main() {
//	ios::sync_with_stdio(false);

//	freopen(".in", "r", stdin);

	int n = next_int<int>();
	int m = next_int<int>();

	vector<string> a(n);
	vector<bool> type(n, 0);
	for(int i = 0; i < n; i++) {
		a[i] = next_token();
	}

	int pr = -1;

	vector<string> b;
	while(m--) {
		int i = next_int<int>() - 1;

		type[i] = 1;
		
		b.push_back(a[i]);

		if(pr == -1 || pr == a[i].size()) {
			pr = a[i].size();
		} else {
			puts("No");
			return 0;
		}	
	}

	string ans = "";
	for(int i = 0; i < pr; i++) {
		char next = b[0][i];
		for(int j = 1; j < b.size(); j++) 
			if(b[j][i] != next) next = '?';

		ans += next;
	}

	for(int i = 0; i < n; i++) {
		if(type[i] || pr != a[i].size()) continue;

		bool ok = 1;
		for(int j = 0; j < pr; j++) {
			if(ans[j] == '?') continue;

			ok &= (ans[j] == a[i][j]);
		}

		if(ok) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	cout << ans << "\n";
}