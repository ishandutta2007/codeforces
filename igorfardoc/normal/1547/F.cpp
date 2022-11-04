#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
}

void do1(int ch, int index, unordered_map<int, unordered_set<int>>& d)
{
	int now = 1;
	while(now * now <= ch)
	{
		if(ch % now == 0)
		{
			if(now != 1)
			{
				d[now].insert(index);
			}
			if(ch / now != 1)
			{
				d[ch / now].insert(index);
			}
		}
		++now;
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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	int gcd1 = 0;
    	bool eq = true;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if(i != 0 && a[i] != a[i - 1])
    		{
    			eq = false;
    		}
    		gcd1 = _gcd(gcd1, a[i]);
    	}
    	if(eq)
    	{
    		cout << "0\n";
    		continue;
    	}
    	for(int i = 0; i < n; i++)
    	{
    		a[i] /= gcd1;
    	}
    	unordered_map<int, unordered_set<int>> ch;
    	for(int i = 0; i < n; i++)
    	{
    		do1(a[i], i, ch);
    	}
    	int ans = 1;
    	for(const auto& el : ch)
    	{
    		vector<int> ind;
    		for(const auto& el1 : el.second)
    		{
    			ind.push_back(el1);
    		}
    		sort(ind.begin(), ind.end());
    		int prev = 0;
    		for(int i = 1; i < ind.size(); i++)
    		{
    			if(ind[i] == ind[i - 1] + 1)
    			{
    				continue;
    			}
    			ans = max(ans, i - prev);
    			prev = i;
    		}
    		ans = max(ans, (int)ind.size() - prev);
    		int start = 0;
    		for(int i = 0; i < ind.size(); i++)
    		{
    			if(i == ind[i])
    			{
    				++start;
    			}
    			else
    			{
    				break;
    			}
    		}
    		for(int i = 0; i < ind.size(); i++)
    		{
    			if(ind[(int)ind.size() - i - 1] == n - 1 - i)
    			{
    				++start;
    			}
    			else
    			{
    				break;
    			}
    		}
    		/*if(el.first == 2)
    		{
    			cout << start << endl << endl;
    		}*/
    		ans = max(ans, start);
    	}
    	cout << ans << '\n';
    }
}