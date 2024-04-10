//Author: HeXun
//Date: 09-04-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 480000;
pair<int, int> p[maxn];
vector<int> G[maxn];
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p + 1, p + n + 1, greater<pair<int, int>>());
	for(int i = 1; i <= n; i += 1) a[i] = p[i].second * 2;
	int tot = n;
	for(int i = 1; i <= n; i += 1){
		if(i + p[i].first - 1 == tot){
			tot += 1;
			a[tot] = p[i].second * 2 - 1;
		}
		else G[i + p[i].first - 1].push_back(p[i].second * 2 - 1);
	}
	//cout << tot << "\n";
	for(int i = 1; i < tot; i += 1) cout << a[i] << " " << a[i + 1] << "\n";
	for(int i = 1; i <= tot; i += 1) for(int j : G[i]) cout << a[i] << " " << j << "\n";
	return 0;
}