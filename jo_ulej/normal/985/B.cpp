#include <iostream>
#include <string>

#define SZ 2000

int n, m;
int a[SZ][SZ];
bool answer = false;

void read()
{
	std::string temp;

	std::cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		std::cin >> temp;

		for(int j = 0; j < m; ++j)
		{
			a[i][j] = int(temp[j] != '0');
		}
	}
}

void solve()
{
	for(int j = 0; j < m; ++j)
	{
		int sum = 0;

		for(int i = 0; i < n; ++i)
			sum += a[i][j];

		for(int i = 0; i < n; ++i)
		{
			a[i][j] *= sum;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		bool temp_flag = true;

		for(int j = 0; j < m; ++j)
		{
			if(a[i][j] == 1)
			{
				temp_flag = false;
				break;
			}
		}

		if(temp_flag)
		{
			answer = true;
			break;
		}
	}
}

void output()
{
	std::cout << (answer ? "YES" : "NO") << std::endl;
}

int main(int argc, char** argv)
{
	read();
	solve();
	output();

	return 0;
}