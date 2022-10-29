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
int S;
ll b[MAXN];

ll check(int k){
	for(int i = 1; i <= n; i++)
		b[i] = a[i] + 1ll * i * k;
	sort(b + 1, b + n + 1);
	ll ret = 0;
	for(int i = 1; i <= k; i++)
		ret += b[i];
	return ret;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &S);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	/*
	sort(a + 1, a + n + 1);
	ll now = 0, k = 0;;
	for(int i = 1; i <= n; i++){
		if (now + a[i] + 1ll * i * (1 + i) / 2 * i <= S)
			now += a[i], k = i;
		else
			break;
	}
	printf("%lld %lld\n", k, now + 1ll * k * (1 + k) / 2 * k);*/
	int l = 0, r = n + 1, m;
	while(l + 1 < r){
		m = (l + r) >> 1;
		if (check(m) <= S)
			l = m;
		else
			r = m;
	}
	printf("%d %lld\n", l, check(l));
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