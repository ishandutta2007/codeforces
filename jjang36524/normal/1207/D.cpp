#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long aeq;
long long beq;
long long alleq;
vector<pair<int, int>>all;
vector<int>a;
vector<int>b;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		all.push_back({ x,y });
		a.push_back(x);
		b.push_back(y);
	}
	sort(all.begin(), all.end());
	all.push_back({ 300001,300001 });
	sort(a.begin(), a.end());
	a.push_back(300001);
	sort(b.begin(), b.end());
	b.push_back(300001);
	aeq = 1;
	beq = 1;
	alleq = 1;
	int nowa=a[0];
	int nowastarted=0;
	for (i = 1; i < N+1; i++)
	{
		if (nowa != a[i])
		{
			nowa = a[i];
			aeq %= 998244353;
			nowastarted = i;
		}
		else
		{
			aeq *= (i - nowastarted + 1);
			aeq %= 998244353;
		}
	}
	int nowb = b[0];
	int nowbstarted = 0;
	for (i = 1; i < N+1; i++)
	{
		if (nowb != b[i])
		{
			nowb = b[i];
			beq %= 998244353;
			nowbstarted = i;
		}
		else
		{
			beq *= (i - nowbstarted + 1);
			beq %= 998244353;
		}
	}
	nowa = all[0].first;
	int nowab = all[0].second;
	int nowabstarted = 0;
	for (i = 1; i < N+1; i++)
	{
		if (nowab > all[i].second)
		{
			alleq = 0;
			break;
		}
		else if (nowa < all[i].first)
		{
			nowa = all[i].first;
			nowab = all[i].second;
			alleq %= 998244353;
			nowabstarted = i;
		}
		else if (nowab < all[i].second)
		{
			nowab = all[i].second;
			alleq %= 998244353;
			nowabstarted = i;
		}
		else
		{
			alleq *= (i - nowabstarted + 1);
			alleq %= 998244353;
		}
	}
	long long totalper = 1;
	for (i = 1; i <= N; i++)
	{
		totalper *= i;
		totalper %= 998244353;
	}
	cout << (totalper - aeq - beq + alleq + 4LL * 998244353) % 998244353;
}