#include <iostream>
#include <vector>

using namespace std;

#define MAX_SUM 900

int main(int argc, char** argv)
{
	int n;
	char tmp;
	vector<int> arr;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr[i] = tmp - '0';
	}

	for(int sum = 0; sum < MAX_SUM; ++sum)
	{
		bool bad = false;
		int temp = arr[0];
		int i = 0;
		int cnt = 0;

		for(;;)
		{
			if(temp == sum)
			{
				//cout << "BREAK: i=" << i << " sum=" << sum << endl;

				++cnt;
				temp = 0;
			}

			if(temp > sum)
			{
				bad = true;
				break;
			}

			if(i == n - 1)
			{
				if(temp < sum && temp != 0)
					bad = true;

				break;
			}

			++i;
			temp += arr[i];
		}

		if(cnt > 1 && !bad)
		{
			cout << "YES" << endl;

			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}