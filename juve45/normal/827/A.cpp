#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100009
#define NMAX 1000009
#define MMAX 1

using namespace std;

int n, k, xmax, x;
string s[DMAX];
int str[NMAX];
string ans;
char a[2*NMAX];


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;	
	s[0] = "a";
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> x;
			xmax = max(xmax, x);
			if(s[str[x]].size() <= s[i].size())
				str[x] = i;
		}
	}

	int last = 1;
	for(int i = 1; i <= xmax; i++)
	{
		for(; last < i + s[str[i]].size(); last++)
		{
			a[last] = s[str[i]][last-i];
		}
	}
	cout << a+1 << '\n';
/*
	for(int i = xmax; i > 0; i--)
	{
		//cout << i << ' ' << s[str[i]] << '\n';
		for(int j = 0; j < s[str[i]].size(); j++)
		{
			if(a[i+j] != 0)
				break;
			a[i+j] = s[str[i]][j];
		}
	}

	//cout << int(a[1]);
	for(int i = 1; i <= xmax; i++)
		if(a[i] == 0)
			a[i] = 'a';
		//dbg_v(a, 10);
	cout << a+1 << '\n';
/*
	//dbg_v(s, 3);
	for(int i = 1; i <= xmax; i++)
	{
		//cout << i << '\n';
		cout << s[str[i]];
		i+=s[str[i]].size()-1;
	}
	cout << '\n';*/
}