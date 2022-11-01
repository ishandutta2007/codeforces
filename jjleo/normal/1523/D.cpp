#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, p;
char a[maxn][62];
vector<int> v;
int cnt[maxn];
long long ans;

void solve(int x){
	v.clear();
	for(int i = 0;i < m;i++) if(a[x][i] == '1') v.push_back(i);
	for(int i = 0;i < (1 << v.size());i++) cnt[i] = 0;
	for(int i = 1;i <= n;i++){
		int val = 0;
		for(int j = 0;j < v.size();j++){
			if(a[i][v[j]] == '1') val |= 1 << j;
		}
		cnt[val]++;
	}
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < (1 << v.size());j++){
			if(j & (1 << i)) cnt[j ^ (1 << i)] += cnt[j];
		}
	}
	int Ans = 0;
	for(int i = 0;i < (1 << v.size());i++){
		if(cnt[i] >= (n + 1) / 2 && __builtin_popcount(i) > __builtin_popcount(Ans)) Ans = i;
	}
	if(__builtin_popcount(Ans) > __builtin_popcountll(ans)){
		ans = 0;
		for(int i = 0;i < v.size();i++) if(Ans & (1 << i)) ans |= 1ll << v[i];
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1;i <= n;i++) scanf("%s", a[i]);
	mt19937 mt(time(0));
	uniform_int_distribution<int> id(1, n);
	for(int i = 1;i <= 50;i++) solve(id(mt));
	for(int i = 0;i < m;i++) printf("%d", (ans & (1ll << i)) != 0);
}