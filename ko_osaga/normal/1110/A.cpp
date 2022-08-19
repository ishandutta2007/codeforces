#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int b, n;
	cin >> b >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int dap = 0;
	for(int i=0; i<n; i++){
		dap = (dap * b + a[i]) % 2;
	}
	puts(dap ? "odd" : "even");
}