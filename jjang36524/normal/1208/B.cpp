#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int N;
int arr[2010];
map<int, int>howmuch;
set<int>hasit;
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		howmuch[arr[i]]++;
		if (howmuch[arr[i]] == 2)
			hasit.insert(arr[i]);
	}
	int startpos = 0;
	int endpos = -1;
	ans = 3000;
	for (; startpos < N; startpos++)
	{
		while (endpos < N&&hasit.size())
		{
			endpos++;
			howmuch[arr[endpos]]--;
			if (howmuch[arr[endpos]] == 1)
				hasit.erase(arr[endpos]);
			
		}
		if (!hasit.size())
			ans = min(ans, endpos - startpos+1);
		howmuch[arr[startpos]]++;
		if (howmuch[arr[startpos]] == 2)
			hasit.insert(arr[startpos]);
	}
	cout << ans;
}