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
ll r, x, y, xx, yy;

void read(){
	cin>>r>>x>>y>>xx>>yy;
}

void solve(){
	r = 4*r * r;
	ll d = (x-xx)*(x-xx)+(y-yy)*(y-yy);
	ll ans = sqrt(d/r);
	while(ans*ans*r < d)
		ans++;
	cout<<ans<<endl;
}

void printans(){

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