#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>x,y,n;
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int i;
		x.clear();
		y.clear();
		n.clear();
		y.push_back(c);
		x.push_back(b);
		for (i = c+1; i <=a; i++)
		{
			if(i!=b)
				x.push_back(i);
		}
		
		for (i = 1; i < b; i++)
		{
			if(i!=c)
				y.push_back(i);
		}
		for (i = 1; i <= a; i++)
		{
			if (i > b && i < c)
				n.push_back(i);
		}
		if (x.size() > a / 2 || y.size() > a / 2)
			cout << -1 << '\n';
		else
		{
			for (i = 0; i < a / 2; i++)
			{
				if (x.size())
				{
					cout << x.back() << ' ';
					x.pop_back();
				}
				else
				{
					cout << n.back() << ' ';
					n.pop_back();
				}
			}
			for (i = 0; i < a / 2; i++)
			{
				if (y.size())
				{
					cout << y.back() << ' ';
					y.pop_back();
				}
				else
				{
					cout << n.back() << ' ';
					n.pop_back();
				}
			}
			cout << '\n';
		}
	}
}