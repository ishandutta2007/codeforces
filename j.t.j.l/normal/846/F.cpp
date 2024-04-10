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

int a[MAXN];
int pos[MAXN];
int pre[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	/*
	for (int i = 1; i <= 1000000; i++)
		pos[i] = 0;
	for (int i = )*/
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans += 1ll * (i - pre[i]) * (n - i + 1);
	}
	ans = ans * 2 - n;
	printf("%.15f\n", 1.0 * ans / (1ll * n * (n)));
}

void printans(){

}


int main(){
	std::ios::sync_with_stdio(false);
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