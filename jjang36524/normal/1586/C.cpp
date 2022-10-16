#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector<string>x;
int psum[1000100];
int main()
{
	int N,M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		x.push_back(s);
	}
	for (i = 1; i < M; i++)
	{
		int bef = 0;
		int cu = 0;
		int j;
		for (j = 1; j < N; j++)
		{
			if (x[j-1][i] == 'X'&&x[j][i-1]=='X')
			{
				psum[i + 1] = 1;
			}
			
		}
		psum[i+1] += psum[i];
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		if (psum[b] == psum[a])
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
}