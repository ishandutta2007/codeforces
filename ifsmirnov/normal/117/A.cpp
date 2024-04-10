#include <iostream>
#include <cstdio>
#include <algorithm>
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios :: sync_with_stdio(false);
	int n, a, b, t, m;
	cin >> n >> m;
	forn(i, n)
	{
		cin >> a >> b >> t;
		a--, b--;
		if (a == b) {cout << t << "\n"; continue;}
		int col = t/(m-1);
		bool up = col%2 == 0;
		int nt;
		if (up)
			nt = (m-1)*col + a;
		else
			nt = (m-1)*col + (m-a-1);
		if (nt < t)
		{
			if (up)
				nt += 2*(m-a-1);
			else
				nt += 2*a;
			up = !up;
		}
		t = nt;
		//cout << a << " " << b << " " << t << " (" << nt << ") " << col << endl;
		if (a<b && up)
			cout << t + (b-a);
		else if (a>b && !up)
			cout << t + (a-b);
		else if (up)
			cout << t + (m-1-a) + (m-1-b);
		else
			cout << t + a + b;
		cout << "\n";
	}
	return 0;
}