#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pw[100];
ll f[100][100];

ll work2(ll n, ll t){
//	cout<<n<<' '<<t<<endl;
	if (n <= 0) return 0;
	if (t < 0) return 0;
	int i = 0;
	for(; pw[i] <= n; i++);
	i--;
	return f[i][t] + work2(n - pw[i], t - 1);
}

ll work(ll n, ll t){
	if (t < 0)
		return 0;
	ll ans = 0;
	for(int i = 0; i <= 41; i++)
		if (pw[i] <= n){
			ans += f[i][t];
			n -= pw[i];
		}
//	cout<<n<<' '<<t<<' '<<ans<<endl;
	//cout<<ans + work(n, t, tmp + 1)<<endl;
	return ans + work2(n, t);
}

int main(){
	ll n, m;
	cin>>n>>m;
	n++;
	pw[0] = 1LL;
	for(int i = 1; i <= 41; i++)
		pw[i] = pw[i-1] * 2;
	int t = -1;
	for(int i = 0; i <= 41; i++)
		if (pw[i] == m){
			t = i;
			break;
		}
	for(int i = 0; i <= 41; i++)
		f[0][i] = 0;
	f[0][0] = 1;
	for(int i = 1; i <= 41; i++){
		f[i][0] = 1;
		for(int j = 1; j <= 41; j++)
			f[i][j] = f[i-1][j-1] + f[i-1][j];
	}
	if (t == -1){
		puts("0");
		return 0;
	}
	else{
		cout<<work(n, t) - (m == 1)<<endl;
	}
	return 0;
}