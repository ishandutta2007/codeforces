#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define M 100001

int main(int argc, char** argv)
{
	int n;
	vector<int> a;
	int stat[M] = {};

	cin >> n;
	a.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n; ++i)
	{
		int d = min(i, n - 1 - i);
		int v = a[i] - d;

		if(v >= 0)
			++stat[v];
	}

	int ans = 1;

	for(int i = 2; i < M; ++i)
	{
		if(stat[i] > stat[ans])
			ans = i;
	}

	cout << n - stat[ans] << endl;

	return 0;
}