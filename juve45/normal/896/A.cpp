#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 100100
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, k, x, maxi, q;
string s;
long long f[DMAX];

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string s1 = "What are you doing while sending \"";// + f(i-1) + 
string s2 = "\"? Are you busy? Will you send \"";// + f(i-1) + 
string s3 = "\"?";

string f1 = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";

string fn(int n)
{
	if(n == 0) return f0;
	string ss = fn(n - 1);
	return s1 + ss + s2 + ss + s3;
}

char res(long long n, long long k)
{
	//dbg(n);

	if(n == 0)
	{
		if(k > f0.size())
			return '.';
		return f0[k - 1];
	}

	if(k <= s1.size())
		return s1[k - 1];
	
	if(k <= s1.size() + f[n - 1])
		return res(n - 1, k - 1LL * s1.size());
	
	if(k <= s1.size() + f[n - 1] + s2.size())
		return s2[k - 1 - 1LL * s1.size() - f[n - 1]];
	
	if(k <= s1.size() + f[n - 1] + s2.size() + f[n - 1])
		return res(n - 1, k - 1LL * s1.size() - 1LL * s2.size() - f[n - 1]);
	
	if(k <= s1.size() + f[n - 1] + s2.size() + f[n - 1] + s3.size())
		return s3[k - 1LL - 1LL * s1.size() - f[n - 1] * 2LL - 1LL * s2.size()];
	
	return '.';
}

void check(int x)
{
	string fk = fn(x);
	dbg(fk.size());
	//dbg(s1.size());
	for(int i = 1; i <= fk.size(); i++)
	{
		if(res(x, i) != fk[i - 1])
		{
			dbg(i);
			exit(0);
		}
	}
	if(res(x, fk.size() + 1) != '.')
	{
		dbg("oups");
		exit(0);
	}
	if(res(x, 1LL * fk.size() + 123521351232351) != '.')
	{
		dbg("oups");
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	f[0] = f0.size();
	s = s1 + f0 + s2 + f0 + s3;
	//dbg(s[193]);
	int maxi = 55;
	for(int i = 1; i <= 100010; i++)
	{
		f[i] = f[i - 1] * 2 + s1.size() + s2.size() + s3.size();

		if(i > maxi)
			f[i] = 2e18;
	}
	/*
	for(int i = 0; i <= 13; i++)
		check(i);
	long long i;
	for(i = 1e18; k < 1000000 ;i--, k++)
	{
		if(res(4235, i) != '.')
			dbg(i);
	}
		//return 0;
	dbg(maxi);
	dbg(f[52]);
	dbg_v(f, maxi);
	string g = fn(1);
	dbg(bool(g == f1));
	*/
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> n >> k;
		if(n <= 12)
		{
			string fk = fn(n);
			if(k <= fk.size())
				cout << fk[k - 1];
			else cout << '.';
		}
		else
			cout << char(res(n, k));

	}
	
}