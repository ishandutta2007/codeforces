#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
int main()
{
	long long sum = 0;
	int i;
	cin >> N;

	vector<long long>a;
	for (i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		sum += x;
	}
	sort(a.begin(), a.end());
	if (N > 1 && (a[0] == a[1]) &&a[0]== 0)
	{
		cout << "cslnb";
		return 0;
	}
	int times = a[0]==a[1];
	for (i = 2; i < N; i++)
	{
		if (a[i] == a[i - 1])
			times++;
		if (times >= 2)
		{
			cout << "cslnb";
			return 0;
		}
		if (a[i] == a[i - 1] && a[i - 1] <= a[i - 2] + 1)
		{
			cout << "cslnb";
			return 0;
		}
	}
	sum -= N * (N - 1) / 2;
	if (sum % 2)
	{
		cout << "sjfnb";
	}
	else
		cout << "cslnb";
}