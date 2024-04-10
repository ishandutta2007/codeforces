#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv)
{
	int n, d, h;
	//vector<pair<int, int>> graph;

	cin >> n >> d >> h;

	if(d - h > h)
	{
		cout << "-1" << endl;
		return 0;
	}

	if(d == 1 && h == 1 && n > 2)
	{
		cout << "-1" << endl;
		return 0;
	}

	for(int i = 1; i <= h; ++i)
		cout << i << " " << i + 1 << endl;

	int M = h + 1;

	if(d > h)
	{
		cout << 1 << " " << h + 2 << endl;

		for(int j = 0; j < d - h - 1; ++j)
			cout << h + j + 2 << " " << h + j + 3 << endl;

		if(d - h - 1 == 0)
			M = h + 2;
		else
			M = d + 1;

		for(int j = M + 1; j <= n; ++j)
			cout << "1 " << j << endl;
	}
	else
	{
		for(int j = M + 1; j <= n; ++j)
			cout << "2 " << j << endl;
	}



	return 0;
}