#include <bits/stdc++.h>
#define x first
#define y second
#define DMAX 200008
#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;


int n, s, x, ans, p[DMAX], k;

int main()
{

	cin >> n;

	for(int i=1;i<=n;i++)
		cin >> p[i];

	for(int i=1;i<=n;i++)
		cin >> x, s+=x;

	if(s%2 == 0) ans++;

	for(int i=1;i<=n;i++)
	{
		if(!p[i]) continue;
		int j = i;
		while(p[j])
		{
			int h = p[j];
			p[j] = 0;
			j=h;
		}
		k++;
	}

	if(k>1) 
		ans += k;

	cout << ans << '\n';

	return 0;
}