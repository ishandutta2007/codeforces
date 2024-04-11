#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;

int vis[7], z1, z2;
int cnt;

void dfs(int x, int h, int mi){
	if(x < z1){
		for(int i=0; i<7; i++){
			if(vis[i]) continue;
			vis[i] = 1;
			dfs(x+1, h*7+i, mi);
			vis[i] = 0;
		}
		return;
	}
	if(x < z1+z2){
		for(int i=0; i<7; i++){
			if(vis[i]) continue;
			vis[i] = 1;
			dfs(x+1, h, mi*7+i);
			vis[i] = 0;
		}
		return;
	}
	if(x == z1+z2){
		if(h < n && mi < m) cnt++;
		return;
	}
}

int main(){
	cin >> n >> m;
	for(int i=n-1; i; i/=7){
		z1++;
	}
	for(int i=m-1; i; i/=7){
		z2++;
	}
	z1 = max(z1, 1); z2 = max(z2, 1);
	if(z1 + z2 > 7){
		puts("0");
		return 0;
	}
	dfs(0,0,0);
	cout << cnt;
}