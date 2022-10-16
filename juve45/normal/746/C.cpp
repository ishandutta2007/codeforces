#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, t1, t2, p, d, x, y, s, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> s >> x >> y;
	cin >> t1 >> t2;
	cin >> p >> d;

	ans = abs(x-y)*t2;
	if(x<y)
	{
		if(d>0)
		{
			if(p <= x)
			{
				ans = min(t1*(y-p), ans);
			}
			else
			{
				ans = min(t1*(s-p+s+y), ans);
			}
		}
		else{
			ans = min(t1*(y+p), ans);
		}
	}
	else{
		if(d>0)
		{
			ans = min(t1*(s-p+s-y), ans);
		}
		else{
			if(p>=x) ans = min(ans, t1*(p-y));
			else ans = min(t1*(s+s+p-y), ans);
		}
	}
	cout << ans << '\n';
	return 0;
}