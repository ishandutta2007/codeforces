#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
char s[MAXM];
int a[MAXM];
int f[MAXN][MAXN];

ll x1, x2, y1,y2;

int sgn(ll x){
	if (x < 0)
		return -1;
	else
		return 1;
}

void read(){
	scanf("%lld%lld", &x1, &y1);
	scanf("%lld%lld", &x2, &y2);
	int cnt = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		ll p, q, r;
		scanf("%lld%lld%lld", &p, &q, &r);
		if (sgn(p * x1 + q * y1 + r) * sgn(p * x2 + q * y2 + r) == -1)
			cnt++;
	}
	cout<<cnt<<endl;
}

void solve(){

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