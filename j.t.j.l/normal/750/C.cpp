#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int a[MAXN], b[MAXN];

void read(){

}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	int p = -2e8, q = 2e8, now = 0;
	for(int i = 1; i <= n; i++){
		if (b[i] == 1){
			p = max(p, 1900 - now);
		}
		else{
			q = min(q, 1899 - now);
		}
		now += a[i];
	}
	if (p > q){
		puts("Impossible");
	}
	else if (q > 1.9e8){
		puts("Infinity");
	}
	else 
		cout<<q + now<<endl;
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