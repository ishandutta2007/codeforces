
#include <iostream>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	while (M--)
	{
		if (N % 10)
			N--;
		else
			N /= 10;
	}
	cout << N;
}