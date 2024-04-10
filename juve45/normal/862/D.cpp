#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, off;
string s;

bool check(int l, int r)
{
	for(int i = 0; i < n; i++)
		s[i] = '0';
	for(int i = l - 1; i < r; i++)
		s[i] = '1';
	cout << "? " << s << endl;
	int newOff;
	cin >> newOff;
	if(abs(off - newOff) == r-l+1) return false;
	return true;
}

int bs(int l, int r)
{
	dbg(l);
	dbg(r);
	if(r == l)
		return l;
	int mid = (l + r) / 2;
	if(check(1, mid))
		return bs(l, mid);
	return bs(mid + 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		s += "0";

	cout << "? "  << s << endl;
	
	cin >> off;

	int l = bs(1, n);

	for(int i = 0; i < s.size(); i++)
		s[i] = '0';
	s[l-1] = '1';
	cout << "? "  << s << endl;
	int newOff;
	cin >> newOff;
	if(newOff < off)
		cout << "! " << 1 << ' ' << l;
	else
		cout << "! " << l << ' ' << 1;

}