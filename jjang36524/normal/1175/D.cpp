#include <iostream>
using namespace std;
int N, K;
int stage;
long long a[300100];
long long ans;
#include <vector>
#include <algorithm>
vector<long long>ini;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int i;
	stage++;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		ans += a[i] * K;
	}
	if(N>1)
		ini.push_back(a[0]);
	for (i = 1; i < N-1; i++)
	{
		ini.push_back(a[i] + ini[i - 1]);
	}
	sort(ini.begin(), ini.end());
	for (i = 0; i < K-1; i++)
	{
		ans -= ini[i];
	}
	cout << ans;
}