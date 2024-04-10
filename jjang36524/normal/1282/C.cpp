#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int eh[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int n, t, a, b;
		cin >> n >> t >> a >> b;
		int easycount = 0;
		int hardcount = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a)
				hardcount++;
			else
				easycount++;
			eh[i] = a;
		}
		vector<pair<int, int>>man;
		int neededtime = 0;
		for (i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			man.push_back({ x,eh[i] });
		}
		sort(man.begin(), man.end());
		int ans = 0;
		int fst = 0, snd = 0;
		int problemtime = max(0LL, man[0].first - 1);
		int temp = fst + snd;
		if ((easycount - fst) * a >= problemtime)
		{
			temp += problemtime / a;
		}
		else
		{
			temp += easycount - fst + min(hardcount - snd, (problemtime - (easycount - fst) * a) / b);
		}
		ans = max(temp, ans);
		for (i = 0; i < n; )
		{
			int nowt = man[i].first;
			
			while (i < n && nowt == man[i].first)
			{
				neededtime += man[i].second ? b : a;
				if (!man[i].second)
					fst++;
				else
					snd++;
				i++;
			}
			int problemtime;
			if (i == n)
				problemtime = t - neededtime;
			else
				problemtime = man[i].first - 1 - neededtime;
			if (problemtime<0)
				continue;
			int temp = fst + snd;
			if ((easycount - fst) * a >= problemtime)
			{
				temp += problemtime / a;
			}
			else
			{
				temp += easycount - fst + min(hardcount-snd,(problemtime - (easycount - fst) * a) / b);
			}
			ans = max(temp, ans);
		}
		cout << ans << '\n';
	}
}