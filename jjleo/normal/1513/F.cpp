#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
int a[maxn], b[maxn];
ll sum;
int ans;
vector<pair<int, int> > v;
multiset<int> st[2];


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n;i++){
		sum += abs(a[i] - b[i]);
		v.push_back({a[i], i}), v.push_back({b[i], i});
	}
	sort(v.begin(), v.end());
	for(int i = 0;i < v.size();i++){
		int x = v[i].first, y = v[i].second;
		if(a[y] > b[y]){
			if(x == b[y]){
				st[0].insert(a[y]);
				if(!st[1].empty()) ans = max(ans, 2 * (min(a[y], *st[1].rbegin()) - b[y]));
			}else{
				st[0].erase(st[0].find(a[y]));
			}
		}else{
			if(x == a[y]){
				st[1].insert(b[y]);
				if(!st[0].empty()) ans = max(ans, 2 * (min(b[y], *st[0].rbegin()) - a[y]));
			}else{
				st[1].erase(st[1].find(b[y]));
			}
		}
	}
	printf("%lld", sum - ans);
}