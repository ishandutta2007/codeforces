#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, q;
lint a[100005];
map<int, lint> mp;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	for(int i=2; i<=n; i++) a[i] += a[i-1];
	cin >> q;
	while(q--){
		int x;
		scanf("%d",&x);
		if(mp.find(x) != mp.end()){
			cout << mp[x] << " ";
			continue;
		}
		lint pw = 1, stp = 0, ret = 0;
		lint pos = 1;
		while(pos < n){
			stp++;
			pw *= x;
			ret += stp * (a[min(1ll * n, pos + pw)] - a[pos]);
			pos += pw;
		}
		mp[x] = ret;
		cout << ret << " ";
	}
}