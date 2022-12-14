#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 505;

int n;
s64 mat[MaxN][MaxN];
s64 row[MaxN], col[MaxN];
s64 diagonal[MaxN];
int empRow = -1, empCol = -1;
int anoRow = -1;

inline bool is_magic_square(const s64 &sum)
{
	for (int i = 1; i <= n; ++i)
	{
		if (row[i] != sum)
			return false;
		if (col[i] != sum)
			return false;
	}
	return diagonal[0] == sum && diagonal[1] == sum;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			mat[i][j] = getint();
			row[i] += mat[i][j];
			col[j] += mat[i][j];
			diagonal[0] += i + j == i + i ? mat[i][j] : 0;
			diagonal[1] += i + j == n + 1 ? mat[i][j] : 0;
			if (mat[i][j] == 0)
				empRow = i, empCol = j;
		}
		if (i != empRow)
			anoRow = i;
	}

	if (n == 1)
	{
		cout << 2333 << endl;
		return 0;
	}

	s64 num = row[anoRow] - row[empRow];
	mat[empRow][empCol] = num;
	row[empRow] += num;
	col[empCol] += num;
	diagonal[0] += empRow == empCol ? num : 0;
	diagonal[1] += empRow + empCol == n + 1 ? num : 0;
	cout << (num > 0 && is_magic_square(row[anoRow]) ? num : -1ll) << endl;

	return 0;
}