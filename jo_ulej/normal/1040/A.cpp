#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int n, a, b;
	vector<int> arr;
	int ans = 0;

	cin >> n >> a >> b;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	for(int i = 0; i < n; ++i)
	{
		int j = n - i - 1;

		if(arr[i] == 0 && arr[j] == 1)
		{
			ans = -1;
			break;
		}

		if(arr[i] == 1 && arr[j] == 0)
		{
			ans = -1;
			break;
		}

		if(arr[i] == 2 && arr[j] == 0)
		{
			arr[i] = 0;
			ans += a;
		}

		if(arr[i] == 2 && arr[j] == 1)
		{
			arr[i] = 1;
			ans += b;
		}

		if(arr[i] == 2 & arr[j] == 2)
		{
			if(a < b)
			{
				arr[i] = 0;
				ans += a;
			}
			else
			{
				arr[i] = 1;
				ans += b;
			}
		}
	}

	cout << ans << endl;

	return 0;
}