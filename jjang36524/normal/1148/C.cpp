#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ac, bc;
int arr[300100];
int rev[300100];
vector<pair<int, int>>x;
signed main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i + 1];
		rev[arr[i + 1]] = i + 1;
	}
	for (i = 1; i <= N / 2; i++)
	{
		if (rev[i] == i)
			continue;
		if (rev[i] != N&&rev[i]<=N/2)
		{
			x.push_back({ rev[i],N });
			int ip = rev[i];
			swap(rev[i], rev[arr[N]]);
			swap(arr[N], arr[ip]);
		}
		else if (rev[i] != N)
		{
			x.push_back({ 1,rev[i] });
			x.push_back({ 1,N });
			x.push_back({ 1,rev[i] });
			int ip = rev[i];
			swap(rev[i], rev[arr[N]]);
			swap(arr[N], arr[ip]);
		}
		x.push_back({ i,rev[i] });
		int ip = rev[i];
		swap(rev[i], rev[arr[i]]);
		swap(arr[i], arr[ip]);
	}
	for (; i <= N; i++)
	{
		if (rev[i] != i)
		{
			x.push_back({ 1,rev[i] });
			x.push_back({ 1,i });
			x.push_back({ 1,rev[i] });
		}
		int ip = rev[i];
		swap(rev[i], rev[arr[i]]);
		swap(arr[i], arr[ip]);
	}
	cout << x.size() << '\n';
	for (i = 0; i < x.size(); i++)
		cout << x[i].first << ' ' << x[i].second << '\n';
}