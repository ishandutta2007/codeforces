#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;


template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

void dfs(int n, int v) {
//	cout << n << " " << v << endl;
	if(n == 0) return;
	if(n == 3) {
		cout << v << " ";
		cout << v << " ";
		cout << 3 * v << " ";
		return;
	}
	if(n == 2) {
		cout << v << " ";
		cout << v * 2 << " ";
		return;
	}
	if(n == 1) {
		cout << v << " ";
		return;
	}
	for(int i = 1; i <= (n + 1) / 2; i++) {cout << v << " ";}
	 dfs(n / 2, v * 2);
}
int n;
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if(n == 2) {
		cout << 1 << " " << 2 << endl;
		return 0;
	}
	if(n == 3) {
		cout << 1 << " " << 1 << " " << 3 << endl;
		return 0;
	}
	dfs(n, 1);
	return 0;
}