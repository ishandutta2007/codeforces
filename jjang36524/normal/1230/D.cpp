#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N;
long long a[7010];
long long b[7010];
set<long long>x;
vector<long long>arr;
long long ans;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	for (i = 0; i < N; i++)
	{
		if (x.count(a[i]))
		{
			arr.push_back(a[i]);
		}
		else
		{
			x.insert(a[i]);
		}
	}
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < arr.size(); j++)
		{
			if ((arr[j] & a[i]) == a[i])
			{
				ans += b[i];
				break;
			}
				
		}
	}
	cout << ans;
}