#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int N, K;
int ord[200100];
int rev[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int curmax = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		cout << a + curmax << ' ';
		curmax = max(curmax, a + curmax);
	}
}