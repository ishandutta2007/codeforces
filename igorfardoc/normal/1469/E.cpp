#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> pref;
string s, sr;

int get(int l, int r)
{
	return pref[r + 1] - pref[l];
}

int conv(int l, int r)
{
	int res = 0;
	for(int i = l; i <= r; i++)
	{
		res *= 2;
		if(sr[i] == '1')
		{
			res += 1;
		}
	}
	return res;
}

string conv1(int a, int k)
{
	string res = "";
	while(a != 0)
	{
		res += '0' + (a % 2);
		a /= 2;
	}
	reverse(res.begin(), res.end());
	string res1 = "";
	for(int i = 0; i < k - res.size(); i++)
	{
		res1 += '0';
	}
	res1 += res;
	return res1;
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
    int q;
    cin >> q;
    while(q--)
    {
    	int n, k;
    	cin >> n >> k;
    	sr = "";
    	cin >> s;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == '0')
    		{
    			sr += '1';
    		}
    		else
    		{
    			sr += '0';
    		}
    	}
    	pref.clear();
    	pref.resize(n + 1);
    	pref[0] = 0;
    	for(int i = 1; i <= n; i++)
    	{
    		pref[i] = pref[i - 1];
    		if(sr[i - 1] == '1')
    		{
    			pref[i]++;
    		}
    	}
    	set<int> set1;
    	for(int i = 0; i < n - k + 1; i++)
    	{
    		int l = i;
    		int r = i + k - 1;
    		if(r - l + 1 <= 20)
    		{
    			set1.insert(conv(l, r));
    		}
    		else if(get(l, r - 20) == 0)
    		{
    			set1.insert(conv(r - 19, r));
    		}
    	}
    	int max1 = 2000000;
    	if(k < 25)
    	{
    		max1 = (1 << k);
    	}
    	bool ok = true;
    	for(int i = 0; i < max1; i++)
    	{
    		if(set1.find(i) == set1.end())
    		{
    			ok = false;
    			cout << "YES\n";
    			cout << conv1(i, k) << '\n';
    			break;
    		}
    	}
    	if(ok)
    	{
    		cout << "NO\n";
    	}
    }
}