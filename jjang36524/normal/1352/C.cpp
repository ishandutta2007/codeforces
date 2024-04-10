#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int T, a, b, c, d;
int main()
{
	cin >> T;
	while (T--)
	{
		long long N, K;
		cin >> N >> K;
		long long p = K /(N - 1)*N;
		cout << p + K % (N - 1)-(!(K%(N-1))) << '\n';
	}
}