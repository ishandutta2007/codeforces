#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<char>> pole;
int n, m, k;

char get_col(int r, int c)
{
	unordered_set<char> s;
	for(int i = 1; i < 26; i++)
	{
		s.insert((char)('a' + i));
	}
	for(int dx = -2; dx <= 2; dx++)
	{
		for(int dy = -2; dy <= 2; dy++)
		{
			int x = r + dx;
			int y = c + dy;
			if(x < 0 || y < 0 || x >= n || y >= m)
			{
				continue;
			}
			auto it = s.find(pole[x][y]);
			if(it != s.end())
			{
				s.erase(it);
			}
		}
	}
	return *(s.begin());
}


void do1()
{
	cout << "YES\n";
	pole.assign(n, vector<char>(m, 'a'));
	if(n % 2 == 0)
	{	
		int am = 0;
		for(int i = 0; i < n - 1; i += 2)
		{
			for(int j = 0; j < m - 1; j += 2)
			{
				if(am == k)
				{
					break;
				}
				char c = get_col(i, j);
				pole[i][j] = c;
				pole[i][j + 1] = c;
				c = get_col(i + 1, j);
				pole[i + 1][j] = c;
				pole[i + 1][j + 1] = c;
				am += 2;
			}
		}
	}
	else
	{
		int am = 0;
		for(int i = 0; i < m - 1; i += 2)
		{
			char c = get_col(0, i);
			pole[0][i] = c;
			pole[0][i + 1] = c;
			++am;
		}
		for(int i = 1; i < n - 1; i += 2)
		{
			for(int j = 0; j < m - 1; j += 2)
			{
				if(am == k)
				{
					break;
				}
				char c = get_col(i, j);
				pole[i][j] = c;
				pole[i][j + 1] = c;
				c = get_col(i + 1, j);
				pole[i + 1][j] = c;
				pole[i + 1][j + 1] = c;
				am += 2;
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(pole[j][i] != 'a')
			{
				continue;
			}
			char c = get_col(j, i);
			pole[j][i] = c;
			pole[j + 1][i] = c;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << pole[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m >> k;
    	if(m % 2 == 1 && k > m / 2 * n)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if(n % 2 == 0 && k % 2 == 0)
    	{
    		do1();
    		continue;
    	}
    	if(n % 2 == 0 && k % 2 == 1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if(m / 2 > k)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	if((k - m / 2) % 2 == 0)
    	{
    		do1();
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}