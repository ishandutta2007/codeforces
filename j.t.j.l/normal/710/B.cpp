#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int a[MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

void solve(){
	sort(a + 1, a + n + 1);
	printf("%d\n", a[(n + 1)/ 2]);
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