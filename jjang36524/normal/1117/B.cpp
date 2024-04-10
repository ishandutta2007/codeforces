#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
vector<int>arr;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,K;
	cin >> N>>M>>K;
	int i;
	int ma = 0;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int s = M / (K+1);
	int f = M - s;
	cout << s * arr[N - 2] + f * arr[N - 1];
}