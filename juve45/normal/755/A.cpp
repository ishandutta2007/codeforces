#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	if(n<100)
	cout << n+2;
else cout << n-2;

	return 0;
}