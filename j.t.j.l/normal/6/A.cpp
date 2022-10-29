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
int f[MAXN][MAXN];

int a, b, c, d;

void read(){
	cin>>a>>b>>c>>d;
}

int tr(int p, int q, int r){
	if (p + q > r && p + r > q && q + r > p)
		return 1;
	else
		return 0;
}

int se(int p, int q, int r){
	if (p + q == r || p + r == q || q + r == p)
		return 1;
	else
		return 0;
}

void solve(){
	if (tr(a,b,c)||tr(a,b,d)||tr(a,d,c)||tr(d,b,c))
		puts("TRIANGLE");
	else
		if (se(a,b,c)||se(a,b,d)||se(a,d,c)||se(d,b,c))
			puts("SEGMENT");
		else
			puts("IMPOSSIBLE");
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