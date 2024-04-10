#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int x,y,z;
		cin >> x >> y >> z;
		int val = 0;
		if(true){
			int a1 = a; int b1 = b; int c1 = c;
			int x1 = x; int y1 = y; int z1 = z;
			int min1 = min(c1,y1);
			c1-=min1; y1-=min1;
			int ans = min1*2;
			int min2 = min(z1,c1);
			z1-=min2; c1-=min2;
			int min3 = min(b1,y1);
			b1-=min3; y1-=min3;
			int rem = b1+c1-x1;
			int rem2 = y1+z1-a1;
			if(rem>0&&rem2>0)ans-=min(rem,rem2)*2;
			val = ans;
		}
		cout << val << "\n";
	}
	return 0;
}