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

char s[1000];
int f[10000];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	scanf("%s", s + 1);
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++){
		if (s[i] != s[i-1])
			f[i] = min(f[i-1], f[i-2]) + 1;
		else
			f[i] = f[i-1] + 1;
	}
	printf("%d\n", f[n]);
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