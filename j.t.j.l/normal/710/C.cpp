#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;

int n, m;
int a[MAXN][MAXN];

void read(){
	scanf("%d", &n);
}

void solve(){
	m = n * n;
	int nn = (n + 1) / 2;
	int p = 1, q = 2;
	for(int i = 1; i <= n; i++){
		a[nn][i] = p;
		p += 2;
	}
	for(int i = 1; i <= n; i++)
		if (i != nn){
			a[i][nn] = p;
			p += 2;
		}
	for(int i = 1; i < nn; i++)
		for(int j = 1; j < nn; j++){
			if (p <= m){
				a[i][j] = p;
				a[n + 1 - i][j] = p + 2;
				a[i][n + 1 - j] = p + 4;
				a[n + 1 - i][n + 1 - j] = p + 6;
				p += 8;
			}
			else{
				a[i][j] = q;
				a[n + 1 - i][j] = q + 2;
				a[i][n + 1 - j] = q + 4;
				a[n + 1 - i][n + 1 - j] = q + 6;
				q += 8;
			}
		}
	for(int i = 1; i <= n ;i++){
		for(int j = 1; j <= n; j++)
			printf("%d%c", a[i][j], " \n"[j == n]);
	}	
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