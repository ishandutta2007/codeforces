#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
string s;



bool correct(string a, string b)
{
	if(a == b)
	{
		return true;
	}
	for(int i = 0; i < min(a.length(), b.length()); i++)
	{
		if(a[i] > b[i])
		{
			return true;
		}
		if(b[i] > a[i])
		{
			return false;
		}
	}
	return a.length() > b.length();
}


bool can(int mid)
{
	vector<int> am(26, 0);
	for(int i = 0; i < mid; i++)
	{
		++am[s[i] - 'a'];
	}
	vector<int> adding(26, 0);
	int can = n - mid;
	for(int i = 0; i < 26; i++)
	{
		if(am[i] == 0)
		{
			continue;
		}
		int need = ((am[i] - 1) / k + 1) * k;
		adding[i] += (need - am[i]);
		can -= need - am[i];
	}
	if(can < 0)
	{
		return false;
	}
	adding['z' - 'a'] += can;
	string str1 = "";
	for(int i = 25; i >= 0; i--)
	{
		for(int j = 0; j < adding[i]; j++)
		{
			str1 += (char)(i + 'a');
		}
	}
	string str2 = "";
	for(int i = mid; i < s.size(); i++)
	{
		str2 += s[i];
	}
	//cout << str1 << ' ' << str2 << endl;
	if(correct(str1, str2))
	{
		return true;
	}
	return false;
}

bool can1(int mid, char c)
{
	vector<int> am(26, 0);
	++am[c - 'a'];
	for(int i = 0; i < mid; i++)
	{
		++am[s[i] - 'a'];
	}
	vector<int> adding(26, 0);
	int can = n - mid - 1;
	for(int i = 0; i < 26; i++)
	{
		if(am[i] == 0)
		{
			continue;
		}
		int need = ((am[i] - 1) / k + 1) * k;
		adding[i] += (need - am[i]);
		can -= need - am[i];
	}
	if(can < 0)
	{
		return false;
	}
	adding[0] += can;
	string str1 = "";
	for(int i = 0; i < mid; i++)
	{
		str1 += s[i];
	}
	str1 += c;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < adding[i]; j++)
		{
			str1 += (char)(i + 'a');
		}
	}
	cout << str1 << '\n';
	return true;
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
    	cin >> n >> k;
    	cin >> s;
    	if(n % k != 0)
    	{
    		cout << "-1\n";
    		continue;
    	}
		while(s.length() < n)
		{
			s += 'a';
		}
		int l = -1;
		int r = n + 1;
		while(r - l > 1)
		{
			int mid = (l + r) / 2;
			if(can(mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		if(l == -1)
		{
			cout << "-1\n";
			continue;
		}
		if(l == n)
		{
			cout << s << '\n';
			continue;
		}
		for(char c = s[l] + 1; c <= 'z'; c++)
		{
			if(can1(l, c))
			{
				break;
			}
		}
    }
}