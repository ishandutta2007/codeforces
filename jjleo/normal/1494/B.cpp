#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, u, r, d, l;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &u, &r, &d, &l);
		bool tag = false;
		int ll = l, rr = r;
		if(u == n) ll--, rr--;
		if(d == n) ll--, rr--;
		if(u == n - 1){
			if(ll > rr) ll--;
			else rr--;
		}
		if(d == n - 1){
			if(ll > rr) ll--;
			else rr--;
		}
		if(ll < 0 || rr < 0) tag = true;
		swap(l, d), swap(r, u);
		ll = l, rr = r;
		if(u == n) ll--, rr--;
		if(d == n) ll--, rr--;
		if(u == n - 1){
			if(ll > rr) ll--;
			else rr--;
		}
		if(d == n - 1){
			if(ll > rr) ll--;
			else rr--;
		}
		if(ll < 0 || rr < 0) tag = true;
		puts(tag ? "NO" : "YES");
	}
}