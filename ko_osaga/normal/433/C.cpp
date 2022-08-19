#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

vi a[100005];

int n, m, p[100005];

lint solve(int x){
	if(a[x].empty()) return 0;
	lint bef = 0;
	for(auto &i : a[x]){
		bef += abs(i - x);
	}
	int p = a[x][a[x].size()/2];
	lint cur = 0;
	for(auto &i : a[x]){
		cur += abs(i - p);
	}
	return cur - bef;
}

int main(){
	cin >> n >> m;
	lint ret = 0;
	for(int i=1; i<=m; i++){
		cin >> p[i];
		if(i != 1 && p[i] != p[i-1]){
			ret += abs(p[i] - p[i-1]);
			a[p[i]].push_back(p[i-1]);
			a[p[i-1]].push_back(p[i]);
		}
	}
	for(int i=1; i<=n; i++) sort(a[i].begin(), a[i].end());
	lint minv = 0;
	for(int i=1; i<=n; i++){
		minv = min(minv, solve(i));
	}
	cout << ret + minv;
}