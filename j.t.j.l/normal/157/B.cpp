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

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

void solve(){
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = n, j = 1; i >= 1; i--){
		ans += j * a[i] * a[i];
		j *= -1;
	}
	printf("%.16f\n", ans * acos(-1));
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