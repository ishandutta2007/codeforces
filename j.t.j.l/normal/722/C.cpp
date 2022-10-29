#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m, M;
int a[MAXN];
ll sum[MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i];
	sum[n+1] = sum[n];
}

void solve(){
	/*
	M = 1;
	for(; M < N; M *= 2);
	for(int i = 1; i <= 2 * M; i++)
		tree[i] = 0;
	for(int i = 1; i <= n; i++)
		tree[i + MM - 1] = 1;
	for(int i = MM - 1; i; i--)
		tree[i] = tree[i<<1] + tree[(i<<1)|1];*/
	set<int> mp;
	map<ll, int> Miao;
	mp.clear();
	mp.insert(0); mp.insert(n+1);
	Miao.clear();
	Miao[sum[n]] = 1;
	for(int i = 1; i <= n; i++){
		int xx;
		scanf("%d", &xx);
		mp.insert(xx);
		auto Maki = mp.find(xx);
		auto Nico = Maki;
		Nico++;
		Maki--;
		ll x = sum[(*Nico)-1]-sum[(*Maki)];
		ll y = sum[(*Nico)-1] - sum[xx];
		ll z = sum[xx-1] - sum[(*Maki)];
	//	cout<<x<<' '<<y<<' '<<z<<endl;
		Miao[x]--;
		if (Miao[x] == 0)
			Miao.erase(x);
		Miao[y]++;
		Miao[z]++;
		printf("%lld\n", Miao.rbegin() -> first);
	}
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