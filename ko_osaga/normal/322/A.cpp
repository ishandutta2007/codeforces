#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int main(){
	int n, m;
	cin >> n >> m;
	printf("%d\n",n+m-1);
	for(int i=1; i<=n; i++) printf("%d 1\n", i);
	for(int i=2; i<=m; i++) printf("1 %d\n", i);
}