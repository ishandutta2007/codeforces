#include<bits/stdc++.h>
#define LOG 19
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


vi get_divisors(int a)
{
	vi ans;
	int i = 2;
	while(i * i <= a)
	{
		if(a % i == 0)
		{
			ans.push_back(i);
			while(a % i == 0)
			{
				a /= i;
			}
		}
		++i;
	}
	if(a != 1)
	{
		ans.push_back(a);
	}
	return ans;
}

ostream& operator<<(ostream& out, vi a)
{
	for(int i = 0; i < a.size(); i++)
	{
		out << a[i] << ' ';
	}
	return out;
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vvi div(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	div[i] = get_divisors(a[i]);
    	//cout << div[i] << endl;
    }
    vvi table(LOG, vi(n + 1));
    unordered_set<int> s;
    int l = 0;
    int r = -1;
    while(l < n)
    {
    	bool can = false;
    	if(r != n - 1)
    	{
    		can = true;
	    	for(int i = 0; i < div[r + 1].size(); i++)
	    	{
	    		if(s.find(div[r + 1][i]) != s.end())
	    		{
	    			can = false;
	    			break;
	    		}
	    	}
	    }
	    if(can)
	    {
	    	++r;
	    	for(int i = 0; i < div[r].size(); i++)
	    	{
	    		s.insert(div[r][i]);
	    	}
	    }
	    else
	    {
	    	table[0][l] = r + 1;
	    	//cout << l << ' ' << r + 1 << endl;
	    	for(int i = 0; i < div[l].size(); i++)
	    	{
	    		s.erase(s.find(div[l][i]));
	    	}
	    	++l;
	    }
	}
	table[0][n] = n;
	for(int st = 1; st < LOG; st++)
	{
		for(int i = 0; i <= n; i++)
		{
			if(i == n)
			{
				table[st][i] = n;
				continue;
			}
			table[st][i] = table[st - 1][table[st - 1][i]];
		}
	}
	for(int o = 0; o < q; o++)
	{
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		int ans = 1;
		int now = l;
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(table[i][now] <= r)
			{
				//cout << i << ' ' << now << ' ' << table[i][now] << endl;
				now = table[i][now];
				ans += (1 << i);
			}
		}
		cout << ans << '\n';
	}
}