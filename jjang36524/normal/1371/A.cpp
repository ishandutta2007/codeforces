#include <iostream>
#include <algorithm>
using namespace std;
int N,M,T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << (N + 1) / 2 << '\n';
	}
}