#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int i = 1;
	int dig = 1;
	while (N>0)
	{
		if (i == 10 || i == 100)
		{
			dig++;
		}
		N -= dig;
		if (N == 0)
		{
			cout << i % 10;
		}
		else if (N == -1)
		{
			cout << (i / 10) % 10;
		}
		else if (N == -2)
		{
			cout << (i / 100) % 10;
		}
		i++;
	}
}