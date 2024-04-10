#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<pair<int, int> > v;

void build(int l, int r){
	if(l == r) return;
	int mid = l + r >> 1;
	build(l, mid), build(mid + 1, r);
	for(int i = 1;i <= mid - l + 1;i++){
		v.push_back({l + i - 1, mid + i});
	}
}

int main(){
	scanf("%d", &n);
	int x = 1;
	for(int i = 20;~i;i--){
		if(n & (1 << i)){
			build(x, x + (1 << i) - 1);
			build(n - (1 << i) + 1, n);
			break;
		}
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++) printf("%d %d\n", v[i].first, v[i].second); 
}