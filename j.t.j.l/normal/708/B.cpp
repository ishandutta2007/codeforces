#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
ll a00, a11, a01, a10;

void read(){
	scanf("%lld%lld%lld%lld", &a00, &a01, &a10, &a11);
}

void solve(){
	ll p = (ll)sqrt(a00 * 2 + 0.5) + 1, q = (ll)sqrt(a11 * 2 + 0.5) + 1;
//	cout<<p<<' '<<q<<endl;
	if (a00 == 0 && a11 == 0){
		if (a01 == 1 && a10 == 0){
			puts("01"); return ;
		}	
		if (a01 == 0 && a10 == 1){
			puts("10"); return ;
		}
		if (a01 == 0 && a10 == 0){
			puts("0"); return ;
		}
		puts("Impossible");
		return ;
	}
	if (a00 == 0){
		if (a01 == 0 && a10 == 0 && q * (q - 1) / 2 == a11){
			for(int i = 1; i <= q; i++)
				putchar('1');
			puts(""); return; 
		}
		if (a01 + a10 == q && q * (q - 1) / 2 == a11){
			for(int i = 1; i <= a10; i++)
				putchar('1');
			putchar('0');
			for(int i = 1; i <= a01; i++)
				putchar('1');
			puts(""); return;
		}
		puts("Impossible");
		return ;
	}
	if (a11 == 0){
		if (a01 == 0 && a10 == 0 && p * (p - 1) / 2 == a00){
			for(int i = 1; i <= p; i++)
				putchar('0');
			puts(""); return; 
		}
		if (a01 + a10 == p && p * (p - 1) / 2 == a00){
			for(int i = 1; i <= a01; i++)
				putchar('0');
			putchar('1');
			for(int i = 1; i <= a10; i++)
				putchar('0');
			puts(""); return;
		}
		puts("Impossible");
		return ;
	}
	if (p * (p - 1) / 2 != a00 || q * (q - 1) / 2 != a11){
		puts("Impossible");
		return ;
	}
	if (p * q != a01 + a10){
		puts("Impossible");
		return ;
	}
	for(int i = 1; i <= a10 / p; i++)
		putchar('1');
	for(int i = 1; i <= p - a10 % p; i++)
		putchar('0');
	if (a10 / p < q) putchar('1');
	for(int i = 1; i <= a10 % p; i++)
		putchar('0');
	for(int i = a10 / p + 2; i <= q; i++)
		putchar('1');
	puts("");
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}