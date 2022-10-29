#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e3 + 10;

char a[MAXN][MAXN];

int main(){
	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%s", a[i]);
	}
	for(int i = 1; i <= n; i++){
		ll cnt = 0;
		for(int j = 0; j < n; j++)
			cnt += (a[i][j] == 'C');
		ans += (cnt - 1) * cnt / 2;
	}
	for(int i = 0; i < n; i++){
		ll cnt = 0;
		for(int j = 1; j <= n; j++)
			cnt += (a[j][i] == 'C');
		ans += (cnt - 1) * cnt / 2;
	}
	cout<<ans<<endl;
	return 0;
}