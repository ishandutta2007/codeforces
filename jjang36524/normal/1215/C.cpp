#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string x, y;
vector<int>abcon;
vector<int>bacon;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>x >>y;
	int i;
	for (i = 0; i < N; i++)
	{
		if (x[i] == 'a' && y[i] == 'b')
			abcon.push_back(i + 1);
		if (x[i] == 'b' && y[i] == 'a')
			bacon.push_back(i + 1);
	}
	if ((abcon.size() + bacon.size()) % 2)
		cout << -1;
	else
	{
		cout << ((abcon.size() + bacon.size()) / 2 + min(abcon.size(), bacon.size()) % 2) << '\n';
		while (abcon.size() != bacon.size())
		{
			if (abcon.size() > bacon.size())
			{
				cout << abcon[abcon.size() - 2] << ' ' << abcon[abcon.size() - 1] << '\n';
				abcon.pop_back();
				abcon.pop_back();
			}
			else
			{
				cout << bacon[bacon.size() - 2] << ' ' << bacon[bacon.size() - 1] << '\n';
				bacon.pop_back();
				bacon.pop_back();
			}
		}
		while (abcon.size())
		{
			if (abcon.size() == 1)
			{
				cout << abcon[0] <<' '<< abcon[0] << '\n';
				cout << abcon[0] << ' ' << bacon[0] << '\n';
				abcon.pop_back();
				bacon.pop_back();
			}
			else
			{
				cout << abcon[abcon.size() - 2] <<' '<< abcon[abcon.size() - 1] << '\n';
				cout << bacon[bacon.size() - 2] << ' ' << bacon[bacon.size() - 1] << '\n';
				abcon.pop_back();
				bacon.pop_back();
				abcon.pop_back();
				bacon.pop_back();
			}
		}
	}
}