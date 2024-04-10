#include <iostream>
#include <vector>

using namespace std;

int n, d;

bool check(int x, int y)
{
	return (d - x - y) * (-y - x + 2 * n - d) <= 0 && (x - d - y) * (-y + x + d) <= 0;
}

int main(int argc, char** argv)
{
	int m, x, y;

	cin >> n >> d;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		cin >> x >> y;

		//cout << (check(x, y) ? "YES" : "NO") << endl;

		if(check(x, y))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}