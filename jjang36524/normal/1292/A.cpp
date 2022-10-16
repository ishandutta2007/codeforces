#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, M;
int arr[200100][3];
set<pair<int, int>>imp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> b >> a;
		int ans = 0;
		if (arr[a][b])
		{
			if (arr[a - 1][3 - b] == 1)
				imp.erase({ a - 1,3 - b });
			if (arr[a][3 - b] == 1)
				imp.erase({ a,0 });
			if(arr[a+1][3-b]==1)
				imp.erase({ a,b });
			arr[a][b] = 0;
		}
		else
		{
			if (arr[a - 1][3 - b] == 1)
				imp.insert({ a - 1,3 - b });
			if (arr[a][3 - b] == 1)
				imp.insert({ a,0});
			if (arr[a + 1][3 - b] == 1)
				imp.insert({ a,b });
			arr[a][b] = 1;
		}
		cout <<( imp.size() ? "No" : "Yes") << '\n';
	}
}