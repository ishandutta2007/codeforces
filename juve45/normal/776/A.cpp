#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;

string s1, s2;
set<string>s;
int n;

int main()
{
	cin >> s1 >> s2;
	s.insert(s1);
	s.insert(s2);

	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cout << *s.begin() << ' ' << *s.rbegin() << '\n';
		cin >> s1 >> s2;
		s.erase(s1);
		s.insert(s2);
	}
		cout << *s.begin() << ' ' << *s.rbegin() << '\n';
}