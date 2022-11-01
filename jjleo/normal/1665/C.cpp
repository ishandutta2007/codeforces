#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], x;
vector<int> v;

bool check(int mid){
	int ans = 0;
	for(int i = 0;i < v.size();i++) ans += max(0, i + v[i] - mid);
	return mid - (int)v.size() >= ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 2;i <= n;i++) scanf("%d", &x), a[x]++;
		v.clear();
		for(int i = 1;i <= n;i++) if(a[i]) v.push_back(a[i]);
		v.push_back(1);
		sort(v.begin(), v.end(), greater<int>());
		int l = 0, r = n, mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}