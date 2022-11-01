#include <iostream>
using namespace std;

bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return false;
	return true;
}
int mirror(int x)
{
	int res = 0;
	while (x)
	{
		res = res*10 + x%10;
		x /= 10;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 2;; i++)
	{
		if (prime(i) && prime(mirror(i)) && i != mirror(i))
			++cnt;
		if (cnt == n)
		{
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}