#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void read(){
	scanf("%d", &n);
}

void solve(){
	printf("2\n");
	for(ll i = 2; i <= n; i++){
		printf("%lld\n", i * (i + 1) * (i + 1) - (i - 1));
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