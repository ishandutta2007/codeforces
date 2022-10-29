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

ll gcd(ll p, ll q){
	return q ? gcd(q, p % q) : p;
}

int a[MAXN], vis[MAXN];

void solve(int casi){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), vis[i] = 0;
	vector<int> b;
	for(int i = 1; i <= n; i++){
		if (!vis[i]){
			int j, fg = 0;
			for(j = i; !vis[j]; j = a[j], fg++){
				vis[j] = 1;
			}
			if (j != i){
				puts("-1");
				return ;
			}
			b.push_back(fg);
		}
	}
	ll ans = 1;
	for(int i = 0; i < b.size(); i++){
		if (b[i] % 2 == 0) b[i] /= 2;
		ll r = gcd(ans, b[i]);
		ans *= (b[i] / r);
	}
	cout<<ans<<endl;
}

void printans(){

}


int main(){
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