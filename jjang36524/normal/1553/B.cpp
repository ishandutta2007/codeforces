#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		string s,t;
		cin >> s >> t;
		int i;
		for (i = 0; i < s.size(); i++)
		{
			string re;
			int j;
			for (j = i; j < s.size(); j++)
			{
				re.push_back(s[j]);
				int k;
				string ne=re;
				for (k = j; k >= 0; k--)
				{
					if (k != j)
						ne.push_back(s[k]);
					if (j - i + 1 + j - k == t.size())
					{
						if (t == ne)
						{
							cout << "YES"<<'\n';
							goto T;
						}
					}
				}
			}
		}
		cout << "NO" << '\n';
	T:
		int d;
	}
}