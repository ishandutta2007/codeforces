#include <iostream>
#include <algorithm>
using namespace std;
int T, N,M, a, b, c, d;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> T >> a >> M;
		int s = a;
		int e = a;
		while (M--)
		{
			cin >> c >> d;
			if (s <= d && e >= c)
			{
				s = min(s, c);
				e = max(e, d);
			}
		}
		cout << e - s + 1 << '\n';
	}
}