#include <iostream>
#include <algorithm>

int main(int argc, char** argv)
{
	int n, m, k;
	int* pos;
	int* name;
	unsigned long long int ans      = 0;

	std::cin >> n >> m >> k;

	pos  = new int[n + 1];
	name = new int[n + 1];

	for(int i = 0; i < n; ++i)
	{
		int a;
		std::cin >> a;

		pos[a] = i + 1;
		name[i + 1] = a;
	}

	for(int step = 0; step < m; ++step)
	{
		int b;
		std::cin >> b;

		int new_scrn = (pos[b] - 1) / k;

		if(pos[b] != 1)
		{
			int a = name[pos[b] - 1];

			std::swap(name[pos[b]], name[pos[a]]);

			--pos[b];
			++pos[a];
		}

		ans += new_scrn + 1;
	}

	delete[] pos;
	delete[] name;

	std::cout << ans << std::endl;

	return 0;
}