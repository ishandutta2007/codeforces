#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

int dx[222];
int dy[222];
string s;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if (s[i] == 'U')
		{
			dx[i+1] = dx[i]+1;
			dy[i+1] = dy[i];
		}
		if (s[i] == 'D')
		{
			dx[i+1] = dx[i]-1;
			dy[i+1] = dy[i];
		}
		if (s[i] == 'L')
		{
			dy[i+1] = dy[i]+1;
			dx[i+1] = dx[i];
		}
		if (s[i] == 'R')
		{
			dy[i+1] = dy[i]-1;
			dx[i+1] = dx[i];
		}
	}


	int ans = 0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<=s.size();j++)
		{
			if(dx[i] == dx[j] && dy[i] == dy[j])
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}