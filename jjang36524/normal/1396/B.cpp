#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
void extgcd(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return;
	}
	int x1, x2;
	extgcd(b, a % b, &x1, &x2);
	*x = x2;
	int q = a / b;
	*y = x1 - q * x2;
}
int N;
pair<int, int>t[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while(N--)
	{
		int M;
		cin >> M;
		int s = 0;
		int j;
		int m = 0;
		for (j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			m = max(m, a);
			s += a;
		}
		if (2 * m > s || s % 2)
		{
			cout << 'T';
		}
		else
			cout << "HL";
		cout << '\n';
	}
	
}