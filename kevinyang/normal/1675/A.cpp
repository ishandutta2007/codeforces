#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,x,y;
		cin >> a >> b >> c >> x >> y;
		if(a<x){
			int v = min(c,x-a);
			c-=v;
			a+=v;
		}
		b+=c;
		if(a>=x&&b>=y){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}