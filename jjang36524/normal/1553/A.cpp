#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << (N + 1) / 10 << '\n';
	}
}