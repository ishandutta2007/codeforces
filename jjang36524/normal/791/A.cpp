#include <iostream>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	int i = 0;
	while (a<=b)
	{
		a *= 3;
		b *= 2;
		i++;
	}
	cout << i;
}