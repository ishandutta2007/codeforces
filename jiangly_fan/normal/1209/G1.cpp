//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
int a[maxn];
int s[maxn];
int CAL(int L, int R){
	map<int, int> mp;
	for(int i = L; i <= R; i += 1) mp[a[i]] += 1;
	int mx = 0;
	for(auto p : mp) mx = max(mx, p.second);
	return R - L + 1 - mx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, q;
	cin >> n >> q;
	set<int> ss;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(not ss.count(a[i])) s[i] += 1;
		ss.insert(a[i]);
	}
	ss.clear();
	for(int i = n; i; i -= 1){
		if(not ss.count(a[i])) s[i] -= 1;
		ss.insert(a[i]);
	}
	int L = 1, p = 0, ans = 0;
	for(int i = 1; i <= n; i += 1){
		p += s[i];
		if(p == 0){
			ans += CAL(L, i);
			L = i + 1;
		}
	}
	cout << ans;
	return 0;
}