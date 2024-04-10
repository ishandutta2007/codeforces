#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[111];
char s[111];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 2; i <= n; i++)
		a[i] = MM;
	a[1] = 0;
	for (int i = 2; i <= n; i++) if (s[i] - '0' == 1){
		for (int j = max(1, i - m); j < i; j++)
			a[i] = min(a[i], a[j] + 1);
	}
	if (a[n] == MM) a[n] = -1;
	printf("%d\n", a[n]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}