#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 5010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, v[DMAX], m, ans;
string s;

int que(int l, int r)
{
	if(l > r)
		return 0;
	if(l > 0)
		return v[r] - v[l - 1];
	else return v[r];
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> s;
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == 'a')
			v[i]++;
	}

	for(int i = 1; i <= s.size(); i++)
		v[i] += v[i - 1];

	//dbg_v(v, s.size());
	for(int i = 0; i <= s.size(); i++)
	{
		for(int j = i; j <= s.size(); j++)
		{
			//[0, i), [i, j), [j, s.size()]
			/*
			dbg(i);
			dbg(j);
			dbg(que(0, i - 1));
			dbg((j - i - que(i, j - 1)));
			dbg(que(j, s.size() - 1));*/
			ans = max(que(0, i - 1) + (j - i - que(i, j - 1)) + que(j, s.size()), ans);
		}
	}
	cout << ans << '\n';
}