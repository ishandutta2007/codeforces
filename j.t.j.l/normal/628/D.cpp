#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

ll pw(ll p, ll q){
	ll ret = 1;
	for(; q; q>>=1){
		if (q & 1){
			ret = ret * p % MM;
		}
		p = p * p % MM;
	}
	return ret;
}

int m, d;
char s[MAXN],t[MAXN];

ll f[2010][2016], g[2016][2016];
ll a[MAXN], b[MAXN];

ll work(char s[], int l){
	s[l] = 0;
	ll now = 0;
	for(int i = 0; i < l; i++)
		if (i & 1){
			now = (now + d * a[l - i]) % m;
		}
//	cout<<now<<endl;
	for(int i = 0; i < l; i++)
		b[i+1] = s[i] - '0';
	for(int i = 0; i <= l + 1; i++)
		for(int j = 0; j <= m; j++)
			f[i][j] = g[i][j] = 0;
	for(int i = 0; i < b[1]; i++)
		if (i != d)
			f[1][i * a[l] % m] += 1;
	if (b[1] != d)
		g[1][b[1] * a[l] % m] = 1;
	int i;
//	puts("#######");
	for(i = 3; i <= l; i += 2){
	//	cout<<i<<endl;
		if (b[i - 1] == d){
//	puts("#######");
			for(int j = 0; j < m; j++)
				if (b[i] != d)
					g[i][(j + a[l + 1 - i] * b[i]) % m] += g[i-2][j];
			for(int j = 0; j < m; j++)
				for(int k = 0; k < b[i]; k++)
					if (k != d)
						f[i][(j + a[l + 1 - i] * k) % m] += g[i-2][j];
			for(int j = 0; j < m; j++)
				for(int k = 0; k < 10; k++)
					if (k != d)
						f[i][(j + a[l + 1 - i] * k) % m] += f[i-2][j];
	//		cout<<"****"<<' ' <<i<<endl;
		}
		else{
			if (b[i-1] > d){
//	puts("^^^^");
				for(int j = 0; j < m; j++)
					for(int k = 0; k < 10; k++)
						if (k != d)
							f[i][(j + a[l + 1 - i] * k) % m] += f[i-2][j] + g[i-2][j];
			}
			else{
//	puts("###2342###");
				for(int j = 0; j < m; j++)
					for(int k = 0; k < 10; k++)
						if (k != d)
							f[i][(j + a[l + 1 - i] * k) % m] += f[i-2][j];
			}
		}
//		cout<<i<<endl;
		for(int j = 0; j < m; j++)
			f[i][j] %= MM, g[i][j] %= MM;
	}
	i -= 2;
	if (i == l)
//	cout<<i<<endl;
//	cout<<(f[i][(m - now) % m] + g[i][(m - now) % m]) % MM<<endl;
		return (f[i][(m - now) % m] + g[i][(m - now) % m]) % MM;
	else{
		if (b[l] < d)
			return (f[i][(m - now) % m]) % MM;
		else
			return (f[i][(m - now) % m] + g[i][(m - now) % m]) % MM;
	}
}

int main(){
	cin>>m>>d;
	scanf("%s", s);
	int l = strlen(s);
	a[1] = 1 % m;
	for(int i = 2; i <= l + 1; i++)
		a[i] = (a[i-1] * 10) % m;
	s[l-1]--;
	for(int i = l - 1; i; i--)
		if (s[i] < '0'){
			s[i-1]--;
			s[i] += 10;
		}
	scanf("%s", t);
//	cout<<work(t,l)<<endl;
//	cout<<work(s,l)<<endl;
	ll ans = work(t, l) - work(s, l);
	cout<<(ans % MM + MM) % MM <<endl;
	return 0;
}