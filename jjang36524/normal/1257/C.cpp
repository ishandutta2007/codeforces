#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N;
int arr[200100];
int main()
{
	int i;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		
		int T;
		cin >> T;
		int ans = 1 << 30;
		set<int>cl;
		for(i=1;i<=T;i++)
		{
			int a;
			cin >> a;
			if (arr[a])
			{
				ans = min(ans,i - arr[a]);
			}
			arr[a] = i;
			cl.insert(a);
		}
		auto a = cl.begin();
		for (; a != cl.end(); a++)
		{
			arr[*a] = 0;
		}
		if (ans > 1000000)
			cout << -1 << '\n';
		else
			cout << ans+1 << '\n';
	}
}