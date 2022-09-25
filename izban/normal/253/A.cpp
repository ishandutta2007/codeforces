#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;



int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	int n, m;
	cin >> n >> m;
	char a = 'B', b = 'G';
	if (n < m)
		swap(a, b), swap(n, m);
	for (int i = 0; i < n + m; i++) {
		if (i % 2 == 0)
			cout << a;
		else if (i % 2 == 1 && i / 2 < m)
			cout << b;
		else cout << a;
	}

	return 0;
}