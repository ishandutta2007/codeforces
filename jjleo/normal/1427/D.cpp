#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
vector<vector<int> > v; 
int l, r;

inline void change(vector<int> b){
	if(b.size() == 1) return;
	v.push_back(b);
	vector<int> c;
	int x = n;
	while(!b.empty()){
		for(int i = 1;i <= b.back();i++){
			c.push_back(a[x - b.back() + i]);
		}
		x -= b.back();
		b.pop_back();
	} 
	for(int i = 1;i <= n;i++) a[i] = c[i - 1];
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			l = r = i;
			break;
		}
	}
	for(int i = 2;i <= n;i++){
		int x;
		for(int j = 1;j <= n;j++){
			if(a[j] == i){
				x = j;
				break;
			}
		}
		vector<int> b;
		if(a[l] >= a[r] && x > r){
			if(n - x) b.push_back(n - x);
			b.push_back(1);
			if(x - l) b.push_back(x - l);
			if(l - 1) b.push_back(l - 1);
		}else if(a[l] <= a[r] && x < l){
			if(n - r) b.push_back(n - r);
			b.push_back(r - l + 1);
			if(l - x) b.push_back(l - x);
			if(x - 1) b.push_back(x - 1);
		}else if(a[l] >= a[r] && x < l){
			if(n - r) b.push_back(n - r);
			for(int k = l;k <= r;k++) b.push_back(1);
			if(l - x) b.push_back(l - x);
			if(x - 1) b.push_back(x - 1);
		}else if(a[l] <= a[r] && x > r){
			if(n - x) b.push_back(n - x);
			if(x - r) b.push_back(x - r);
			for(int k = l;k <= r;k++) b.push_back(1);
			if(l - 1) b.push_back(l - 1);
		}
		reverse(b.begin(), b.end());
		change(b);
		for(int j = 1;j <= n;j++){
			if(a[j] == 1 || a[j] == i){
				l = j, r = j + i - 1;
				break;
			}
		}
	}
	if(a[1] == n){
		vector<int> b(n, 1);
		change(b);
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++){
		printf("%d ", v[i].size());
		for(int j = 0;j < v[i].size();j++) printf("%d ", v[i][j]);
		puts("");
	}
	
}