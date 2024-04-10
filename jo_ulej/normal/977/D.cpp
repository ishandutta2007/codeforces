#include <iostream>

#define MSIZE 100

typedef long long int lli_t;

lli_t matrix[MSIZE][MSIZE];

int px = -1;
int py = -1;

void put(lli_t val)
{
	lli_t tmp = val;

	int x = 0;
	int y = 0;

	while(tmp % 2 == 0)
	{
		tmp /= 2;
		++x;
	}

	while(tmp % 3 == 0)
	{
		tmp /= 3;
		++y;
	}

	matrix[x][y] = val;

	if(px == -1)
	{
		px = x;
		py = y;
	}

	if(x < px || y > py)
	{
		px = x;
		py = y;
	}
}

void parent(int& mx, int& my)
{
	mx = px;
	my = py;
}

bool next(int& x, int& y)
{
	if(x + 1 < MSIZE && matrix[x + 1][y] != -1)
	{
		++x;

		return true;
	}

	if(y - 1 >= 0 && matrix[x][y - 1] != -1)
	{
		--y;

		return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	int n;
	lli_t temp;

	for(int i = 0; i < MSIZE; ++i)
	{
		for(int j = 0; j < MSIZE; ++j)
			matrix[i][j] = -1;
	}

	std::cin >> n;

	for(int i = 0; i < n; ++i)
	{
		std::cin >> temp;

		put(temp);
	}

	int x, y;
	parent(x, y);

	std::cout << matrix[x][y] << " ";

	while(next(x, y))
		std::cout << matrix[x][y] << " ";

	std::cout << std::endl;

	return 0;
}