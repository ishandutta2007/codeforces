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

double sqr(double x){
	return x * x;
}

void read(){
	scanf("%d%d", &n, &m);
	double ans = 0;
	double p, q;
	for(int i = 1; i <= n; i++){
		double x, y;
		scanf("%lf%lf", &x, &y);
		if (i != 1){
			ans += sqrt(sqr(x - p) + sqr(y - q));
		}
		p = x, q = y;
	}
	printf("%.15f\n", ans * m / 50.0); 
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