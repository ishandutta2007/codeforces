#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, ans, a, b, c;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	

cin >> a >> b >> c;
ans = min(a, b/2);
ans = min(ans, c/4);
cout << ans*7;
	return 0;
}