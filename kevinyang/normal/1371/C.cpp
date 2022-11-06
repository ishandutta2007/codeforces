#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		long long a,b,n,m;
		cin >> a >> b >> n >> m;
		bool f = true;
		long long c = min(a,b);
		long long d = max(a,b);
		c-=m;
		//cout << c << " " << d << " " << n << " "
		if(c<0)f = false;
		if(c+d<n)f = false;
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}