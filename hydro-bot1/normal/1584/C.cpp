// Hydro submission #619a1f4e1f2c1185421a8893@1637490511030
#include <bits/stdc++.h>
using namespace std;
int t,n,a[101],b[101]; 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			if(b[i]-a[i]!=1&&b[i]!=a[i])
			{
				cout << "NO" << endl;
				goto end;
			}
		cout << "YES" << endl;
end:;
	}
	return 0;
}