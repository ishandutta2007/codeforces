#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,m;
		cin >> a >> b >> c >> m;
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a>b)swap(a,b);
		int mn = 0;
		int mx = a-1+b-1+c-1;
		if(a==0)mx++;
		if(b==0)mx++;
		if(c==0)mx++;
		
		c-=b+a;
		mn = c-1;
		mn = max(mn,0LL);
		if(m>=mn&&m<=mx){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}