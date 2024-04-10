#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e5 + 10;
const int MAKI = 9;

int n, m;

void prework(){

}

void read(){

}

ll ans;

map<ll, int> mp;
ll c[MAXN], a[MAXN];
int b[MAXN];
ll K;
int l[MAXN], r[MAXN];
ll ret[MAXN];

int MP[MAXN << 1];
int ksn[MAXN], kke[MAXN], nco[MAXN];

void add(int x, int flag){
	if (flag == 1){
		ans += MP[kke[x]];//mp[c[x] - K];
		MP[nco[x]]++;
		//mp[c[x]]++;
	}
	else{
		ans += MP[ksn[x - 1]];//mp[c[x - 1] + K];
		MP[nco[x - 1]]++;
		//mp[c[x - 1]]++;
	}
}

void sub(int x, int flag){
	if (flag == 1){
		MP[nco[x]]--;
		ans -= MP[kke[x]];
		//mp[c[x]]--;
		//ans -= mp[c[x] - K];
	}
	else{
		MP[nco[x - 1]]--;
		ans -= MP[ksn[x - 1]];
		//mp[c[x - 1]]--;
		//ans -= mp[c[x - 1] + K];
	}
	//cout << "SUB " << x << ' ' << flag << ' ' << ans << endl;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%lld", &n, &K);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	c[0] = 0;
	//mp.reserve(1024);
	//mp.max_load_factor(0.25);
	mp[0] = 1;
	mp[K] = 1;
	mp[-K] = 1;	
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if (b[i] == 1)
			c[i] = c[i-1] + a[i];
		else
			c[i] = c[i-1] - a[i];
		mp[c[i]] = 1;
		mp[c[i] + K] = 1;
		mp[c[i] - K] = 1;
	}
	int m = 0;
	for (auto &x : mp){
		m++;
		x.second = m;
	}
	for (int i = 0; i <= n; i++){
		kke[i] = mp[c[i] - K];
		nco[i] = mp[c[i]];
		ksn[i] = mp[c[i] + K];
	}
	MP[nco[0]] = 1;
	int Q;
	scanf("%d", &Q);
	vector<PPI> f;
	for (int i = 1; i <= Q; i++){
		scanf("%d%d", &l[i], &r[i]);
		f.push_back((PPI){(PII){l[i] >> MAKI, ((l[i] >> MAKI) & 1) ? -r[i] : r[i]}, i});
	}
	sort(f.begin(), f.end());
	int L = 1, R = 0;
	ans = 0;
	for (int i = 0; i < Q; i++){
		int x = l[f[i].second], y = r[f[i].second];
		while(R < y) add(++R, 1);
		while(L > x) add(--L, -1);
		while(R > y) sub(R--, 1);
		while(L < x) sub(L++, -1);
		//cout << L << ' ' << R << ' ' << x << ' ' << y << endl;
		ret[f[i].second] = ans;
	}
	for (int i = 1; i <= Q; i++)
		printf("%lld\n", ret[i]);
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