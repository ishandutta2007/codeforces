#include <iostream>
#include <algorithm>
#include <string>

#define SZ 100

std::string intake;
int n;

int ans[SZ][SZ];

int solve(int i, int j)
{
	if(ans[i][j] == -1)
	{
		if(intake[i] != intake[j])
		{
			ans[i][j] = j - i + 1;
		}
		else if(j != i + 1)
		{
			if(solve(i + 1, j - 1) == j - i - 1)
			{
				ans[i][j] = j - i + 1;
			}
			else
			{
				ans[i][j] = std::max(solve(i + 1, j), solve(i, j - 1));
			}
		}
		else
		{
			ans[i][j] = 0;
		}
	}

	return ans[i][j];
}

int main(int argc, char** argv)
{
	std::cin >> intake;
	n = intake.size();

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			ans[i][j] = -1;
	}

	std::cout << solve(0, n - 1) << std::endl;

	return 0;
}