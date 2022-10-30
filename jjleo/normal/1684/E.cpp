#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];
map<int, int> mp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0;i < n;i++) a[i] = 0;
		mp.clear();
		for(int i = 1;i <= n;i++){
			int x;
			scanf("%d", &x);
			if(x < n) a[x]++;
			else mp[x]++;
		}
		int pos = 0;
		int K = k;
		while(pos < n){
			if(a[pos]) pos++;
			else if(K == 0) break;
			else pos++, K--;
		}
		vector<int> v;
		for(auto it : mp) v.push_back(it.second);
		for(int i = pos;i < n;i++) if(a[i]) v.push_back(a[i]);
		sort(v.begin(), v.end(), greater<int>());
		pos = 0;
		while(a[pos]) pos++;
		while(k){
			if(v.empty()) break;
			k--;
			v[v.size() - 1]--;
			if(v.back() == 0) v.pop_back();
			a[pos]++;
			while(a[pos]) pos++;
		} 
		printf("%d\n", v.size());
	}
}