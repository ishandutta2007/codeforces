#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 200009

using namespace std;

string s, t;
int a[DMAX], h;
bool check(int k)
{
	string st;
	for(int i=0; i< s.size();i++)
		if(a[i] > k)
			st += s[i];

	int j = 0;
	for (int i = 0; i < st.size(); ++i)
	{
		if(t[j] == st[i])
			j++;
		if(j == t.size())
			return true;
	}

	if(j == t.size())
		return true;
	return false;
}

int cb(int l, int r)
{
	if(l == r)
		return l;
	int mid = (l+r+1)/2;
/*	dbg(l);
	dbg(r);
	dbg(mid);
	dbg(check(mid));
*/
	if(check(mid) == true)
	  return cb(mid, r);
	else 
		return cb(l, mid-1);
}

int main()
{
	cin >> s;
	cin >> t;

	for(int i=0;i<s.size();i++)
	{
		cin >> h;
		a[h-1] = i+1;
	}


	cout << cb(0, s.size());

}