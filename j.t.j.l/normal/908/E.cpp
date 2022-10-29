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

ll f[1024];
char s[1024];

ll a[1024][1024];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &m, &n);
	map<ll, int> mp;
	for (int i = 1; i <= n; i++){
		scanf("%s", s);
		for (int j = 1; j <= m; j++){
			f[j] = f[j] * 2 + (s[j - 1] - '0');
		}
	}
	for (int j = 1; j <= m; j++)
		mp[f[j]]++;
	a[1][1] = 1;
	for (int i = 2; i <= m + 1; i++){
		a[i][1] = a[i-1][i-1];
		for (int j = 2; j <= i; j++)
			a[i][j] = (a[i][j-1] + a[i-1][j-1]) % MM;
	}
	ll ans = 1;
	for (auto &x : mp)
		ans = (ans * a[x.second + 1][1]) % MM;
	cout << ans << endl;
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