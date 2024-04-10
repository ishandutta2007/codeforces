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

vector<int> E[MAXN];
int a[MAXN], fa[MAXN];

map<int, int> mp[2];

int dfs(int u){
	int len = 0;
	//cout << u << endl;
	for(int v, i = 0; i < E[u].size(); i++){
		v = E[u][i];
		len = 1 - dfs(v);
	}
	//cout << u << ' ' << len << endl;
	mp[len][a[u]]++;
	return len;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	//puts("??");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	//	mp[a[i]]++;
	}
	//puts("??");
	for(int i = 2; i <= n; i++){
		scanf("%d", &fa[i]);
		E[fa[i]].push_back(i);
	}
	//puts("??");
	dfs(1);
	int umi = 0;
	for(auto &x : mp[0]){
		if (x.second & 1)
			umi ^= x.first;
	}
	ll ans = 0;
	if (umi == 0){
		ll cnt = 0;
		for(auto &x : mp[0])
			cnt += x.second;
		ans += cnt * (cnt - 1) / 2;
		cnt = 0;
			//ans += 1ll * x.second * (x.second - 1) / 2;
		for(auto &x : mp[1])
			cnt += x.second;
		ans += cnt * (cnt - 1) / 2;
			//ans += 1ll * x.second * (x.second - 1) / 2;
	}
	for(auto &x : mp[0]){
		auto maki = mp[1].find(umi ^ x.first);
		if (maki != mp[1].end())
			ans += 1ll * x.second * maki->second;
	}
	printf("%lld\n", ans);
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