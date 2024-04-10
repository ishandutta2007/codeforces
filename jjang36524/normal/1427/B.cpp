#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int>t;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M,T;
	cin >> T;
	while (T--)
	{
		t.clear();
		cin >> N>>M;
		string s;
		cin >> s;
		int befs = -1;
		int i;
		vector<int>p;
		int r = M;
		int c = 1;
		for (i = 0; i < N; i++)
		{
			r += s[i] == 'W';
			if (s[i] == 'W')
			{
				if (befs != i - 1&&befs!=-1)
				{
					p.push_back(i - 1 - befs);
					c++;
				}
				befs = i;
			}
		}
		if (r == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		sort(p.begin(), p.end());
		r = min(r, N);
		int curans = r+(r-c);
		int an = 0;
		for (i = 0; i < p.size(); i++)
		{
			if (an + p[i] <= M)
			{
				an += p[i];
				curans++;
			}
			else
				break;
		}
		cout << curans << '\n';
	}
}