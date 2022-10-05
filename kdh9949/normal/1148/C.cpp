#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], p[N];
vector<int> r, s;

void put(int x, int y){
	r.push_back(x);
	s.push_back(y);
	swap(p[a[x]], p[a[y]]);
	swap(a[x], a[y]);
}

void mySwap(int x, int y){
	if(x > y) swap(x, y);
	if(y - x >= n / 2){
		put(x, y);
	}
	else if(y <= n / 2){
		put(x, n);
		put(y, n);
		put(x, n);
	}
	else if(x > n / 2){
		put(1, x);
		put(1, y);
		put(1, x);
	}
	else{
		put(x, n);
		put(1, n);
		put(1, y);
		put(1, n);
		put(x, n);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		p[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		if(p[i] != i) mySwap(i, p[i]);
	}
	printf("%d\n", r.size());
	for(int i = 0; i < r.size(); i++) printf("%d %d\n", r[i], s[i]);
}