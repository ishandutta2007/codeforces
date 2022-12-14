#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

int main()
{
	s64 n, m, k;
	cin >> n >> m >> k;
	s64 u = (n - 1) / k + 1;
	s64 v = (m - 1) / k + 1;
	cout << u * v << endl;

	return 0;
}