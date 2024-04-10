#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

char n, m;
int cnt = 0;

void read(){
	scanf("%c%c", &n, &m);
}

void solve(){
	if (n == 'a' || n == 'h')
		cnt++;
	if (m == '8' || m == '1')
		cnt++;
	if (cnt == 0) puts("8");
	else if (cnt == 1) puts("5");
	else puts("3");
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