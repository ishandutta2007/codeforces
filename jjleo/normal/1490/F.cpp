#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
map<int, int> mp;
int x;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			mp[x]++;
		}
		v.clear();
		for(map<int, int>::iterator it = mp.begin();it != mp.end();++it){
			v.push_back(it->second);
		}
		sort(v.begin(), v.end());
		int ans = n, sum = 0;
		for(int i = 0;i < v.size();i++){
			ans = min(ans, n - sum - ((int)v.size() - i) * v[i] + sum);
			sum += v[i];
		}
		printf("%d\n", ans);
	}
}