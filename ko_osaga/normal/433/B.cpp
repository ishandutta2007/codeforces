#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n;
lint a[100005], b[100005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	for(int i=1; i<=n; i++){
		a[i] += a[i-1];
		b[i] += b[i-1];
	}
	int q;
	cin >> q;
	while(q--){
		int t, l, r;
		scanf("%d %d %d",&t,&l,&r);
		if(t == 2) printf("%lld\n",b[r] - b[l-1]);
		else printf("%lld\n",a[r] - a[l-1]);
	}
}