#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, d;
int a[maxn];

bool cal(int x, int mid){
	if(!x) return false;
	vector<int> v;
	for(int i = 0;i <= n;i++) if(x ^ i) v.push_back(a[i]);
	for(int i = 0;i + 1 < v.size();i++) if(v[i + 1] - v[i] - 1 < mid) return false;
	if(d - v.back() - 1 >= mid) return true;
	for(int i = 0;i + 1 < v.size();i++) if(v[i + 1] - v[i] - 1 >= mid * 2 + 1) return true;
	return false;
}

bool check(int mid){
	int x = -1;
	for(int i = 0;i < n;i++) if(a[i + 1] - a[i] - 1 < mid){
		x = i;
		break;
	}
	if(x == -1) return true;
	return cal(x, mid) || cal(x + 1, mid);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		check(1);
		int l = 0, r = d, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l); 
	}
}