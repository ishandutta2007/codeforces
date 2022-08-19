#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
lint a[100005], b[100005];
lint pmax[100005], pmin[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<n; i++) b[i] = abs(a[i] - a[i+1]);
	for(int i=2; i<n; i+=2) b[i] *= -1;
	for(int i=1; i<=n; i++) b[i] += b[i-1];
	pmax[n-1] = pmin[n-1] = b[n-1];
	for(int i=n-2; i>0; i--){
		pmax[i] = max(pmax[i+1], b[i]);
		pmin[i] = min(pmin[i+1], b[i]);
	}
	lint ret = -1e18;
	for(int i=1; i<n; i+=2){
		ret = max(ret, pmax[i] - b[i-1]);
	}
	for(int i=2; i<n; i+=2){
		ret = max(ret, b[i-1] - pmin[i]);
	}
	cout << ret;
}