//Author: HeXun
//Date: 10-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
int t[maxn];
int sum[maxn];
void add(int x, int p){
	for(; x < maxn; x += x & -x) sum[x] += p;
}
int find(int x){
	int res = 0;
	for(; x; x -= x & -x) res += sum[x];
	return res;
}
set<int> wait;
queue<int> q;
LL ans[maxn];
struct event{
	LL t;
	int id;
	bool s;
	bool operator < (const event& e)const{
		if(t != e.t) return t < e.t;
		if(s != e.s) return s > e.s;
		return id < e.id;
	}
};
set<event> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, p;
	cin >> n >> p;
	for(int i = 1; i <= n; i += 1){
		cin >> t[i];
		s.insert({t[i], i, true});
	}
	for(int i = 1; i <= n; i += 1) add(i, 1);
	LL qt = 0, t = 0;
	while(not s.empty() or not wait.empty()){
		if(not wait.empty()){
			int x = *wait.begin();
			if(find(x) == x){
				wait.erase(x);
				qt = max(qt, t);
				ans[x] = qt += p;
				add(x, -1);
				s.insert({ans[x], x, false});
				continue;
			}
		}
		auto p = *s.begin();
		s.erase(p);
		t = p.t;
		if(p.s) wait.insert(p.id);
		else add(p.id, 1);
	}
	for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
	return 0;
}