#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a[200005], p[200005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		a[i+n] = a[i];
	}
	for(int i=1; i<2*n; i++){
		p[i] = p[i-1] + (a[i-1] > a[i]);
	}
	for(int i=0; i<n; i++){
		if(p[n-i] == p[2*n-1-i]){
			printf("%d", i);
			return 0;
		}
	}
	puts("-1");
}