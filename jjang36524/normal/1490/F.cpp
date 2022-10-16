#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
map<int, int>t;
int cou[200100];
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		t.clear();
		memset(cou, 0, sizeof(cou));
		cou[0] = 987654321;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t[a]++;
			cou[t[a] - 1]--;
			cou[t[a]]++;
		}
		int cur = 0;
		int ans = N;
		for (i = N; i >=1; i--)
		{
			cur += cou[i];
			ans = min(ans, N - cur * i);
		}
		cout << ans << '\n';
	}
}