#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

typedef pair<int, int> point;

const ll mod = 1e7 + 9;

bool my_cmp(point a, point b)
{
	if(a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

void solve()
{
	int n;
	vector<point> arr1, arr2;

	cin >> n;

	arr1.resize(n);
	arr2.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr1[i].first >> arr1[i].second;

	for(int i = 0; i < n; ++i)
		cin >> arr2[i].first >> arr2[i].second;

	sort(arr1.begin(), arr1.end(), my_cmp);
	sort(arr2.begin(), arr2.end(), my_cmp);

	int x = arr1[0].first + arr2[n - 1].first;
	int y = arr1[0].second + arr2[n - 1].second;

	cout << x << " " << y << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}