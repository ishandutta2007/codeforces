#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;

int n, k;
string s;
int l[MAXN], r[MAXN], good[MAXN];
vector<int> ord;

void dfs(int x){
	if(~l[x]) dfs(l[x]);
	ord.push_back(x);
	if(~r[x]) dfs(r[x]);
}

bool solve(int x, int c){
	bool toMark = 0;
	if(~l[x]){
		bool used = solve(l[x], c + 1);
		if(used) toMark = 1;
	}
	if(!toMark && good[x] && c <= k){
		toMark = 1;
		k -= c;
	}
	if(toMark) cout << s[x] << s[x];
	else cout << s[x];
	if(~r[x]) solve(r[x], toMark ? 1 : 1e9);
	return toMark;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i], l[i]--, r[i]--;
	dfs(0);
	for(int i = 0; i < sz(ord); ){
		int j = i;
		while(j < sz(ord) && s[ord[i]] == s[ord[j]]) j++;
		if(j < sz(ord) && s[ord[i]] < s[ord[j]]){
			for(int k = i; k < j; k++) good[ord[k]] = 1;
		}
		i = j;
	}
	solve(0, 1);
}