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
	m = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if (a[i] == 1)
			m = -1;
	}
}

void solve(){
	
}

void printans(){
	cout<<m<<endl;
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