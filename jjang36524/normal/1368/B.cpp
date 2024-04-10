#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define int long long
using namespace std;
int N, M, a, b, d;
int arr[10];
char c[11] = "codeforces";
signed main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	int r = sqrt(N);
	int i;
	int ans = 1;
	for (i = 0; i < 10; i++)
		arr[i] = 1;

	for (i = 0;ans<N; i++)
	{
		arr[i % 10]++;
		ans *= arr[i % 10];
		ans /= (arr[i % 10] - 1);
	}
	for (i = 0; i < 10; i++)
	{
		int j;
		for (j = 0; j < arr[i]; j++)
		{
			cout << c[i];
		}
	}
}