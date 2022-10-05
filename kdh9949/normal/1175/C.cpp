#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, a[N];

int main(){
	int t;
	scanf("%d", &t);
	for(; t--; ){
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		int mn = int(2e9), mi;
		for(int i = 0; i + k < n; i++){
			if(mn > a[i + k] - a[i]){
				mn = a[i + k] - a[i];
				mi = (a[i] + a[i + k]) / 2;
			}
		}
		printf("%d\n", mi);
	}
}