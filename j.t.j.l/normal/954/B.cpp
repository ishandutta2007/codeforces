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
	int ans = n;
	for (int i = 1; i * 2 <= n; i++){
		int flag = 1;
		for (int j = 1, k = i + 1; j <= i; j++, k++)
			if (s[j] != s[k])
				flag = 0;
		if (flag){
			ans = min(ans, i + 1 + (n - 2 * i));
		}
	}
	printf("%d\n", ans);
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