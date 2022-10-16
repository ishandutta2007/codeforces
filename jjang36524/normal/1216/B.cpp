#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<pair<long long, int>>arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back({ a,i + 1 });
	}
	sort(arr.begin(), arr.end());
	long long ans = 0;
	for (i = 0; i < N; i++)
	{
		ans += (N - i - 1) * arr[i].first + 1;
	}
	cout << ans << '\n';
	for (i = N - 1; i >= 0; i--)
	{
		cout << arr[i].second << ' ';
	}
}