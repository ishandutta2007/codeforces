#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1500005;

int n, m;
lint a[MAXN], b[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0; i<m; i++) scanf("%lld",&b[i]);
	lint qq = 0;
	for(int i=n-1; i; i--){
		qq = gcd(qq, abs(a[i] - a[i-1]));
	}
	for(int i=0; i<m; i++){
		lint g = a[0] + b[i];
		if(qq) g = gcd(g, qq);
		printf("%lld ", g);
	}
}