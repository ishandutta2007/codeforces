#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int n;
map<int, int> mp;
int x, ans;
int a[maxn];
int sum;
vector<int> v;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		mp[x]++;
	}
	for(map<int, int>::iterator it = mp.begin();it != mp.end();++it){
		a[it->second]++;
	}
	for(int i = n;i;i--) a[i] += a[i + 1];
	sum = n;
	for(int i = n;i;i--){
		sum -= a[i + 1];
		if(sum / i >= i){
			if(sum / i * i > ans){
				ans = sum / i * i;
				x = i;
			}
		}
	}
	for(map<int, int>::iterator it = mp.begin();it != mp.end();++it){
		if(it->second < x) continue;
		for(int i = 1;i <= it->second && v.size() < ans && i <= x;i++) v.push_back(it->first);
		if(v.size() == ans) break;
	}
	for(map<int, int>::iterator it = mp.begin();it != mp.end();++it){
		if(it->second >= x) continue;
		for(int i = 1;i <= it->second && v.size() < ans && i <= x;i++) v.push_back(it->first);
		if(v.size() == ans) break;
	}
	printf("%d\n%d %d\n", ans, x, ans / x);
	for(int i = 1;i <= x;i++){
		int now = i, val = i;
		for(int j = 1;j <= ans / x;j++){
			a[now] = v[val - 1];
			now++;
			if(now > ans / x) now = 1;
			val += x;
		}
		for(int j = 1;j <= ans / x;j++) printf("%d ", a[j]);
		puts(""); 
	}
}