#include <iostream>
#include <map>

using namespace std;

#define MOD  1000000007ll

long long a[100000];
long long cache;
long long t;
long long n;
long long x;
map<long long, long long> nums;

int main()
{
	cin >> n >> x;
	for (long long i = 0;i < n;i++)
	{
		cin >> a[i];
		t += a[i];
	}
	for (long long i = 0;i < n;i++)
		nums[t-a[i]]++;
	map<long long, long long>::iterator it = nums.begin();
	while (it != nums.end())
	{
		if ((*it).second < x)
			break;
		nums[(*it).first] -= x;
		nums[(*it).first+1ll]++;
		if ((*it).second == 0)
			it++;
	}
	long long power = (*it).first;
	if (power > t) power = t;
// power
	long long ans = 1;
	cache = x;
	if (power%2ll) ans = cache;
	power /= 2ll;
	while (power)
	{
		cache *= cache;
		cache %= MOD;
		if (power%2ll)
		{
			ans *= cache; ans %= MOD;
		}
		power /= 2ll;
	}
	cout << ans << endl;
	return 0;
}