#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	
	while (N--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if ((a == d) && (a == (b + c)))
			cout << "YES" << '\n';
		else if ((b == c) && (b == (a + d)))
			cout << "YES" << '\n';
		else if ((b == d) && (b == (a + c)))
			cout << "YES" << '\n';
		else if ((a == c) && (a == (b + d)))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}