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
	cin.tie(NULL);
	cin >> N;
	int i;
	cout << 7 +3*(N-1)<< '\n';
	for (i = 0; i < N; i++)
	{
		if (!i)
		{
			cout << i << ' ' << i << '\n';
			cout << i << ' ' << i + 1 << '\n';
			cout << i + 1 << ' ' << i << '\n';
			cout << i + 1 << ' ' << i + 1 << '\n';
		}
		
		cout << i+ 1 << ' ' <<  i+2 << '\n';
		cout << i + 2 << ' ' <<  i + 1 << '\n';
		cout << i + 2 << ' ' <<  i + 2 << '\n';
	}
}