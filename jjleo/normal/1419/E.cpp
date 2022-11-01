#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
vector<pair<int, int> > v;
vector<int> a;
map<int, bool> mp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v.clear();
		int x = n;
		for(int i = 2;i * i <= n;i++){
			int cnt = 0;
			while(x % i == 0) cnt++, x /= i;
			if(cnt) v.push_back({i, cnt});
		}
		if(x ^ 1) v.push_back({x, 1});
		a.clear();
		for(int i = 1, j = v[0].first;i <= v[0].second;i++, j *= v[0].first) a.push_back(j);
		mp.clear();
		for(int i = 1;i < v.size();i++){
			int x = v[i].first, y = v[i].second;
			a.push_back(x * v[i - 1].first), mp[a.back()] = true;
			for(int k = 1, l = x;k <= y;k++, l *= x) a.push_back(l);
			for(int j = (int)a.size() - 2 - y;~j;j--){
				for(int k = 1, l = x;k <= y;k++, l *= x){
					if(mp[a[j] * l]) continue;
					a.push_back(a[j] * l), mp[a[j] * l] = true;
				}
			}
			
		}
		int ans = 0;
		for(int i = 0;i < a.size();i++) ans += __gcd(a[i], a[(i + 1) % a.size()]) == 1;
		for(int i = 0;i < a.size();i++) printf("%d ", a[i]);
		puts("");
		printf("%d\n", ans);
	}
}