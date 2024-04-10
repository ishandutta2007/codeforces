#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;
string s, a, sol;
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;
	int i=0;
	if(n%2 == 1)
	{
		sol.push_back(s[0]);
		i++;
	n--;
	}
	while(n)
	{
		n-=2;
		a.push_back(s[i]);
		i++;
		sol.push_back(s[i]);
		i++;
	}
	reverse(a.begin(), a.end());
	cout << a << sol<< '\n';
	return 0;
}