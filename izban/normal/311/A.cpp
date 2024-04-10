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

const int maxn = 1 << 13;
const int inf = 1000000007;
const int mod = 1000000007;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	int n, k;
	cin >> n >> k;
	if (n * (n - 1) / 2 > k) {
		for (int i = 0; i < n; i++) cout << 0 << " " << i << endl;
	} else cout << "no solution";

	return 0;
}