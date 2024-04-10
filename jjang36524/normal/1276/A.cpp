#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		string a;
		cin >> a;
		vector<int>ans;
		int s = a.size();
		int i;
		for (i = 0; i < s; i++)
		{
			if (a[i] != 'o')
			{
				continue;
			}
			int situ = 0;
			if ((i > 1 && a[i - 2] == 't' && a[i - 1] == 'w'))
				situ += 1;
			if (i <= s - 3 && a[i + 1] == 'n' && a[i + 2] == 'e')
				situ += 2;
			if (situ == 3)
				ans.push_back(i + 1);
			if (situ == 2)
				ans.push_back(i + 2);
			if (situ == 1)
				ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for (i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}