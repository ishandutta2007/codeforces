#include <bits/stdc++.h>
#define x first
#define y second
#define DMAX 200008
#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;


int n, s, x, ans, p[DMAX], k, s90, pay;
queue<pair<int, int> > q90, q;


int main()
{

	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> x;

		while(!q90.empty() && x - q90.front().x >= 90)
		{
			s90-=q90.front().y;
			q90.pop();
		}
		pay = min(50-s90, 20);

		while(!q.empty() && x - q.front().x >= 1440)
		{
			s-=q.front().y;
			q.pop();
		}

		pay = min(pay, 120 - s);
		cout << pay << '\n';
		q90.push({x, pay});
		s90 += pay;
		q.push({x, pay});
		s += pay;
	}

	return 0;
}