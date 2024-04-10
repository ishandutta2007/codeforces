#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 400100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, g[DMAX], f[DMAX], m, nri;
string s, a[DMAX];
vector <int> imp;
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		f[s[i]]++;
	}

	for(int i = 0; i <= 255; i++)
		if(f[i] % 2 == 1)
		{
			imp.push_back(i);
			nri++;
			f[i]--;
		}

	if(nri == 0)
	{
		cout << 1 << '\n';
		string ans;
		for(int i = 0; i < 255; i++)
			while(f[i])
				ans += char(i),
				f[i] -= 2;

		cout << ans;
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	else{
		for(int i = 1; i <= n; i++)
		{
			if(n % i != 0)
				continue;

			if(i < nri)
				continue;

			if((i - nri) % 2 == 0)
			{

				int sz = n / i;
				if(sz % 2 == 0)
					continue;
				cout << i << '\n';
				for(int j = 0; j < nri; j++)
				{
					a[j] += char(imp[j]);
				}
				int last = nri;

				for(int j = 0; j < 255 && last < i; j++)
				{
					//dbg(j);
					//dbg(last);
					//dbg(i);
					while(f[j] > 0 && last < i)
					{
						//dbg(last);
						a[last] += char(j);
						last++;
						a[last] += char(j);
						last++;
						f[j]-=2;
					}
				}
				//dbg_ok;
				string buff;
				for(int j = 0; j < 255; j++)
					while(f[j]) 
						buff.push_back(char(j)), f[j] -= 2;

				for(int j = 0; j < i; j++)
				{
					string tmp;
					for(int k = 0; k < sz/2; k++)
						tmp += buff.back(), buff.pop_back();
					cout << tmp << a[j];
					reverse(tmp.begin(), tmp.end());
					cout << tmp << ' '; 
				}
				return 0;
			}
		}
	}
}