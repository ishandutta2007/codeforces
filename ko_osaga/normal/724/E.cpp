#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint d[10005];
int n, c, p[10005], s[10005];

int main(){
	scanf("%d %d",&n,&c);
	for(int i=1; i<=n; i++) scanf("%d",&p[i]);
	for(int i=1; i<=n; i++) scanf("%d",&s[i]);
	for(int i=1; i<=n; i++){
		for(int j=i; j>=0; j--){
			if(j != i) d[j] = d[j] + p[i] + 1ll * j * c;
			else d[j] = 1e18;
			if(j > 0) d[j] = min(d[j], d[j-1] + s[i]);
		}
	}
	cout << *min_element(d, d+n+1);
}