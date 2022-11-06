#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(int x, int y, int a, int b, int c, int d){
	int d1 = a+c; int d2 = max(b,d);
	if(d1>d2)swap(d1,d2);
	if(x>y)swap(x,y);
	return d1<=x&&d2<=y;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int x,y,a,b,c,d;
	cin >> x >> y >> a >> b >> c >> d;
	bool ans = false;
	if(f(x,y,a,b,c,d)){
		ans = true;
	}
	swap(a,b);
	if(f(x,y,a,b,c,d)){
		ans = true;
	}
	swap(c,d);
	if(f(x,y,a,b,c,d)){
		ans = true;
	}
	swap(a,b);
	if(f(x,y,a,b,c,d)){
		ans = true;
	}
	if(ans)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}