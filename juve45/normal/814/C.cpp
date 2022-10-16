#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, pre[44][1502], q;
string s;

bool check(int lg, int sub, int chr)
{
	char c = chr;
	int f[256];
	memset(f, 0, sizeof f);

	for(int i = 0; i < lg; i++)
	{
		f[s[i] - 'a']++;
	}

	if(lg - f[chr] <= sub)
		return true;

	for(int i = lg; i < s.size(); i++)
	{
		f[s[i] - 'a']++;
		f[s[i-lg] - 'a']--;
		if(lg - f[chr] <= sub)
			return true;
	}
	//dbg(lg);
	//dbg(sub);
	//dbg(c);
	//dbg_v(f, 26);
	return false;
}

int compute(int chr, int x)
{
	int l = 1, r = n;
	while(l != r)
	{
		int mid = (l+r+1)/2;
		int tr = check(mid, x, chr);
		//dbg(tr);
		if(tr)
			l = mid;
		else r = mid-1;
	}
	return l;
}


int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int x;
		string y;
		cin >> x >> y;
		if(pre[y[0]-'a'][x] == 0)
			pre[y[0]-'a'][x] = compute(y[0]-'a', x);
		cout << pre[y[0]-'a'][x] << '\n';
	}

}