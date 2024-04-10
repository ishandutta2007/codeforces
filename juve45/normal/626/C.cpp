#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> a >> b;

	for(int i=1;i<5000000;i++)
	{
		if(i/2 + i/3 -i/6 >= a+b && i/2 >=a && i/3 >=b)
		{
			cout << i;
			return 0;
		}
	}


	return 0;
}