//Author: HeXun
//Date: 08-18-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
vector<LL> k[64];
vector<int> G[maxn];
map<LL, int> mp;
int ans = maxn;
void add(LL u, LL v){
	if(not mp.count(u)) {
		int x = mp.size();
		mp[u] = x + 1;
	}
	if(not mp.count(v)) {
		int x = mp.size();
		mp[v] = x + 1;
	}
	u = mp[u];
	v = mp[v];
	G[u].push_back(v);
	G[v].push_back(u);
}
int d[128][128];
void solve(int u){
	int t = 0;
	set<int> s;
	for(int v : G[u]){
		if(s.count(v)) continue;
		t += 1;
		s.insert(v);
		for(int i = 1; i <= (int)mp.size(); i += 1) d[t][i] = maxn;
		queue<int> q;
		d[t][v] = 0;
		q.push(v);
		while(not q.empty()){
			int x = q.front();
			q.pop();
			for(int y : G[x]) if(d[t][y] > d[t][x] + 1 and y != u){
				d[t][y] = d[t][x] + 1;
				q.push(y);
			}
		}
	}
	if(t < 2) return;
	for(int i = 1; i <= (int)mp.size(); i += 1){
		vector<int> v;
		for(int j = 1; j <= t; j += 1) v.push_back(d[j][i]);
		sort(v.begin(), v.end());
		ans = min(ans, v[0] + v[1] + 2);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i += 1){
		LL a;
		cin >> a;
		for(int j = 0; j <= 62; j += 1) if((a >> j) & 1) k[j].push_back(a);
	}
	for(int j = 0; j <= 62; j += 1) if(k[j].size() > 2) no(3);
	for(int j = 0; j <= 62; j += 1) if(k[j].size() == 2 and k[j][0] != k[j][1]) add(k[j][0], k[j][1]);
	//for(auto p : mp) cout << p.first << " " << p.second << '\n';
	//for(int j = 0; j <= (int)mp.size(); j += 1){
	//	for(int k : G[j]) cout << j << " " << k << "\n";
	//}
	for(int i = 1; i <= (int)mp.size(); i += 1) solve(i);
	cout << (ans == maxn ? -1 : ans);
	return 0;
}