#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<char> > a;
vector<vector<char> > a1;


bool check(int r1, int c1, int r2, int c2)
{
	if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 || r1 >= n || c1 >= n || r2 >= n || c2 >= n)
	{
		return false;
	}
	if(c1 == c2)
	{
		int up = max(r1, r2);
		int down = min(r1, r2);
		if(up - down != 2)
		{
			return false;
		}
		if(a[down][c1] == 'X' && a[down + 1][c1] == 'X' && a[up][c1] == 'X')
		{
			return true;
		}
	}
	else if(r1 == r2)
	{
		int up = max(c1, c2);
		int down = min(c1, c2);
		if(up - down != 2)
		{
			return false;
		}
		if(a[r1][down] == 'X' && a[r1][down + 1] == 'X' && a[r1][up] == 'X')
		{
			return true;
		}
	}
	return false;
}



bool need(int i, int j)
{
	bool res = false;
	res = res || check(i, j, i + 2, j);
	res = res || check(i - 1, j, i + 1, j);
	res = res || check(i - 2, j, i, j);
	res = res || check(i, j, i, j + 2);
	res = res || check(i, j - 1, i, j + 1);
	res = res || check(i, j - 2, i, j);
	return res;
}


int get_res1(int diag)
{
	if(diag > 2 * n - 2)
	{
		return 0;
	}
	int res = 0;
	for(int i = 0; i <= diag; i++)
	{
		if(need(i, diag - i))
		{
			++res;
			a[i][diag - i] = 'O';
		}
	}
	return res + get_res1(diag + 3);
}
int get_res2(int diag)
{
	if(abs(diag) > n - 1)
	{
		return 0;
	}
	int res = 0;
	for(int i = max(0, diag); i <= min(n - 1, diag + n - 1); i++)
	{
		if(need(i, i - diag))
		{
			++res;
			a[i][i - diag] = 'O';
		}
	}
	return res + get_res1(diag + 3);
}
void printans()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j];
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
    	cin >> n;
    	a.assign(n, vector<char>(n));
    	a1.assign(n, vector<char>(n));
    	int amount = 0;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < n; j++)
    		{
    			cin >> a1[i][j];
    			if(a1[i][j] == 'X')
    			{
    				amount++;
    			}
    		}
    	}
    	amount /= 3;
    	a = a1;
    	int res = get_res1(0);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    	a = a1;
    	res = get_res1(1);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    	a = a1;
    	res = get_res1(2);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    	a = a1;
    	res = get_res2(-n + 1);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    	a = a1;
    	res = get_res2(-n + 2);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    	a = a1;
    	res = get_res2(-n + 3);
    	if(res <= amount)
    	{
    		printans();
    		continue;
    	}
    }
}