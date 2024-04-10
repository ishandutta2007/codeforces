#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2e3 + 10;
const int MM = 1e9 + 7;

ll f[MAXN][MAXN];
char s[100000 + 10];

int main(){
	int n, m;
	cin>>n>>m;
	scanf("%s", s);
	f[0][0] = 1;
	for(int i = 1; i <= n - m; i++){
		f[i][0] = f[i-1][1];
		for(int j = 1; j <= i; j++)
			f[i][j] = (f[i-1][j+1] + f[i-1][j-1]) % MM;	
	}
	int x = 0, y = 0;
	for(int i = 0; i < m; i++){
		 x += (s[i] == '(') - (s[i] == ')');
		 y = min(y, x);
	}
	ll ans = 0;
	for(int i = 0; i <= n - m; i++)
		for(int j = 0; j <= i; j++)
			if (j + y >= 0)
				if (j + x <= n - m && j + x >= 0)
					ans += f[i][j] * f[n - m - i][j + x] % MM;
	cout<<ans % MM<<endl;
	return 0;
}