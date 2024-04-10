#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e6 + 3;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

ll n, m;
char s[MAXM];
int a[MAXM];
int f[MAXN][MAXN];

void read(){
	cin>>n>>m;
}

ll pw(ll q, ll p){
	ll ret = 1;
	for(; p; p>>=1){
		if (p & 1)
			ret = (ret * q) % MM;
		q = q * q % MM;
	}
	return ret;
}

void solve(){
//	cout<<n<<' '<<m<<endl;
	ll cnt = 0;
	int o = 0;
	for(ll u = m - 1; u; u /= 2)
		o++;
	if (n < o){
	//	cout<<n<<' '<<o<<endl;
		puts("1 1");
		return ;
	}
	m--;
	for(ll i = m; i; i /= 2)
		cnt += i / 2;
//	cout<<cnt<<endl;
	ll INV = pw(2, MM - 2);
//	cout<<pw(pw(2, n), m)<<endl;
	ll B = pw(pw(2, n), m) * pw(INV, cnt) % MM;
//	cout<<B<<endl;
	ll A = 1;
	ll C = pw(2, n);
	ll p = 1, q = 1;
	for(int i = 0; i < MM; i++){
		p = p * ((C - i) % MM + MM) % MM;
	}
	for(int i = 1; i <= m % MM; i++){
		q = q * ((C - i) % MM + MM) % MM;
	}
//	cout<<p<<' '<<q<<endl;
	A = pw(p, m / MM) * q % MM * pw(INV, cnt) % MM;
//	A = A * pw(INV, cnt);
	A = ((B - A) % MM + MM) % MM;
	cout<<A<<' '<<B<<endl;
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}