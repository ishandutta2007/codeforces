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
		cin >> a >> b;
		cout << min((a + b) / 3, min(a, b))<<'\n';
	}
}