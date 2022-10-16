#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <string>
using namespace std;
int N, M;
vector<int>h;
int uf[200100];
int coun;
int f(int x)
{
	if (uf[x] == x)
		return x;
	return uf[x] = f(uf[x]);
}
void u(int a, int b)
{
	if (f(a) == f(b))
		return;
	coun--;
	uf[f(a)] = uf[f(b)];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		h.clear();
		int parti = 1;
		int score = a;
		while (parti <= a)
		{
			h.push_back(score);
			if (a / parti - (a / (parti + 1)))
			{
				parti++;
				score = (a / (parti));
			}
			else
			{
				if (score == 1)
					break;
				score--;
				parti = a / score;
			}
		}
		h.push_back(0);
		cout << h.size() << '\n';
		while (h.size())
		{
			cout << h[h.size() - 1] << ' ';
			h.pop_back();
		}
		cout << '\n';
	}
}