#include <iostream>
using namespace std;
long long r[2000100];
int main()
{
	r[1] = 4;
	int i;
	for (i = 2; i <= 2000000; i++)
	{
		r[i] = r[i - 1] + 2 * r[i - 2] + ((i % 3)==1)*4;
		r[i] %= 1000000007;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		cout << (a > 2 ? r[a - 2] : 0)<<'\n';
	}
}