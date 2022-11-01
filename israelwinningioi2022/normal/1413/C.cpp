#include <iostream>
#include <vector>
#include <algorithm>
 
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define big (ll)10000000000000000
using namespace std;
 
 
/*
 
sum, a index, b index
 
*/
 
 
void finish(ll num)
{
	cout << num << endl;
	exit(0);
}
int main()
{
	vll a(6);
	for (ll i = 0; i < 6; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll n;
	cin >> n;
	vll b(n);
	for (ll i = 0; i < n; i++) cin >> b[i];
	vpll arr;
	//vector< pair<ll, pll>> arr;
	for (ll i = 0; i < 6; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			arr.push_back({ b[j] - a[i], j });
		}
	}
 
	sort(arr.begin(), arr.end());
 
	/*
	cout << "arr: " << endl;
	for (ll i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
 
	}
	cout << endl;
	*/
 
	ll ans = big;
	ll curans = 0;
	vll reached(n, 0);
	ll reachednum = 0;
	ll last = -1;
	while (reachednum < n)
	{
		last++;
		if (reached[arr[last].second] == 0)
		{
			//reached[arr[last].second] = true;
			reachednum++;
		}
		reached[arr[last].second]++;
 
	}
	ll start = 0;
	while (true)
	{
		//cout << "start: " << start << " last: " << last << endl;
		if (last >= arr.size()) finish(ans);
		ans = min(ans, arr[last].first - arr[start].first);
		ll curj = arr[start].second;
		reached[curj]--;
		start++;
		while (reached[curj] == 0)
		{
			last++;
			if (last >= arr.size()) finish(ans);
			reached[arr[last].second]++;
		}
 
	}
 
	finish(ans);
	
 
}