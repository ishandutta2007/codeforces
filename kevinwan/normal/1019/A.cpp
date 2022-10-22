#include <algorithm>
#include<vector>
#include <functional>
#include <queue>
#include <iostream>
#define mid (l+r)/2
using namespace std;
typedef long long ll;


int n, m;
vector<ll> v[3001];
vector<ll> k;
int mmm() {
	int ret = 0;
	for (int i = 2; i <= m; i++) {
		if (v[i].size() > v[ret].size())ret = i;
		if (v[ret].size()!=0&&v[i].size() == v[ret].size() && v[i][0] < v[ret][0])ret = i;
	}
	return ret;
}
ll fir(int q) {
	ll ret = 0;
	for (int i = 0; i < min(q,n); i++)ret += k[i];
	return ret;
}
int main() {
	int i,j;
	ll ans = 0x3f3f3f3f3f3f3f3f, acc = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		int a; ll b;
		scanf("%d%lld", &a, &b);
		v[a].push_back(b);
		if(a!=1)k.push_back(b);
	}
	sort(k.begin(), k.end());
	for (i = 1; i <= m; i++)sort(v[i].begin(), v[i].end());
	for (i = 0; i < n; i++) {
		int qq = mmm();
		ans = min(ans, acc + fir(v[qq].size() - v[1].size()+1));
		if (qq == 0)break;
		acc += v[qq][0];
		k.erase(find(k.begin(),k.end(),v[qq][0]));
		v[qq].erase(v[qq].begin());
		v[1].push_back(0);
	}
	printf("%lld", ans); getchar(); getchar();
}