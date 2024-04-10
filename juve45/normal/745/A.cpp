#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;
map<string, int> m;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	
cin>>s;
m[s];
	for(int i=1;i<=55;i++)
	{
		string s2;
		s2.push_back(s.back());
		s2.append(s);
		s2.pop_back();
		m[s2];
		s=s2;
	}
	cout << m.size();


	return 0;
}