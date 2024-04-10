//Author: HeXun
//Date: 09-23-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 8000;
LL a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	for(int i = 0; i < n; i += 1) cin >> b[i];
	map<LL, int> mp;
	for(int i = 0; i < n; i += 1) mp[a[i]] += 1;
	vector<LL> v;
	for(auto p : mp) if(p.second >= 2) v.push_back(p.first);
	LL ans = 0;
	for(int i = 0; i < n; i += 1){
		bool ok = false;
		for(LL x : v) if((x & a[i]) == a[i]) ok = true;
		if(ok) ans += b[i];
	}
	cout << ans;
	return 0;
}